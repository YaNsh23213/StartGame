// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Tasks/SPAttackSystemTask.h"
#include "AIController.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "Player/AnimNotify/SPEndAnimatoinAnimNotify.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/DamageType.h"
#include "Player/SPBaseCharacter.h"
#include "GameFramework/DamageType.h"
#include "Player/Component/SPHealthComponent.h"
#include "Engine/DamageEvents.h"

#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"

USPAttackSystemTask::USPAttackSystemTask() {}

EBTNodeResult::Type USPAttackSystemTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Controller = OwnerComp.GetAIOwner();
    BBComponent = OwnerComp.GetBlackboardComponent();
    if (!Controller || !BBComponent) return EBTNodeResult::Failed;

    Pawn = Cast<ASPEnemyCharacter>(Controller->GetPawn());
    if (!Pawn) return EBTNodeResult::Failed;

    const auto Component = Pawn->FindComponentByClass<USPHealthAIAComponent>();
    if (!Component) return EBTNodeResult::Failed;

    const auto FocusActor = Cast<ASPBaseCharacter>(BBComponent->GetValueAsObject(FocusKeyName));
    if (FocusActor->GetEnemyActor() == nullptr)
    {
        FocusActor->SetEnemyActor(Pawn);
    }
    FocusActor->SetBSStatus(true);

    auto CurrentHealth = Component->GetCurrentHealth();
    if (CurrentHealth > 80 && CurrentHealth <= 100)
    {
        if (Pawn->GetPhaseActionInProgress() == false)
        {
            UE_LOG(LogTemp, Display, TEXT("Phase 1 HP %f"), CurrentHealth);
            InitActionPhase1();
            Pawn->SetPhaseActionInProgress(true);
            Controller->SetFocus(FocusActor);
        }
    }
    if (CurrentHealth > 0 && CurrentHealth <= 80)
    {
        if (Pawn->GetPhaseActionInProgress() == false)
        {
            UE_LOG(LogTemp, Display, TEXT("Phase 2 HP %f"), CurrentHealth);
            InitActionPhase2();
            Pawn->SetPhaseActionInProgress(true);
        }
    }
    return EBTNodeResult::Succeeded;
}

void USPAttackSystemTask::InitActionPhase1()
{
    if (!Pawn || !Pawn->GetAnimMontagePhase1()) return;
    Pawn->PlayAnimMontage(Pawn->GetAnimMontagePhase1());
    const auto NotifyEvents = Pawn->GetAnimMontagePhase1()->Notifies;
    for (auto NotifyEvent : NotifyEvents)
    {
        EndAnimatoinAnimNotify = Cast<USPEndAnimatoinAnimNotify>(NotifyEvent.Notify);

        if (EndAnimatoinAnimNotify)
        {
            EndAnimatoinAnimNotify->OnEndAnimation.AddUObject(this, &USPAttackSystemTask::EndPhaseOne);
        }
    }
}

void USPAttackSystemTask::InitActionPhase2()
{
    const auto FocusActor = Cast<AActor>(BBComponent->GetValueAsObject(FocusKeyName));
    Controller->MoveToActor(FocusActor, 200.0f, true, true, true, 0, true);
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &USPAttackSystemTask::HalfPhase2, 0.5f, true);
}

void USPAttackSystemTask::EndPhaseOne()
{
    const auto Location = Pawn->GetMesh()->GetSocketLocation("SpawnCast");
    const auto EnemyLocation = Cast<AActor>(BBComponent->GetValueAsObject(FocusKeyName))->GetActorLocation();
    const auto LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Pawn->GetActorLocation(), EnemyLocation);
    FActorSpawnParameters SpawnParams;
    UE_LOG(LogTemp, Display, TEXT("Use Cast"));
    GetWorld()->SpawnActor<AActor>(SpellPhase1, Location, LookAtRotation, SpawnParams);
    Pawn->SetPhaseActionInProgress(false);
    EndAnimatoinAnimNotify->OnEndAnimation.Clear();
}

void USPAttackSystemTask::HalfPhase2()
{
    const auto Enemy = Cast<AActor>(BBComponent->GetValueAsObject(FocusKeyName));
    auto Distance = Pawn->GetDistanceTo(Enemy);
    UE_LOG(LogTemp, Display, TEXT("Distance %f"), Distance);
    if (Distance < 300.0f)
    {
        UE_LOG(LogTemp, Display, TEXT("Distance Melee"));
        if (!Pawn || !Pawn->GetAnimMontagePhase2()) return;
        Pawn->PlayAnimMontage(Pawn->GetAnimMontagePhase2());
        const auto NotifyEvents = Pawn->GetAnimMontagePhase2()->Notifies;
        for (auto NotifyEvent : NotifyEvents)
        {
            EndAnimatoinAnimNotify = Cast<USPEndAnimatoinAnimNotify>(NotifyEvent.Notify);

            if (EndAnimatoinAnimNotify)
            {
                UE_LOG(LogTemp, Display, TEXT("SetDelegate"));
                EndAnimatoinAnimNotify->OnEndAnimation.AddUObject(this, &USPAttackSystemTask::EndPhaseTwo);
                GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
            }
        }
    }
}
void USPAttackSystemTask::EndPhaseTwo()
{
    const auto Enemy = Cast<ASPBaseCharacter>(BBComponent->GetValueAsObject(FocusKeyName));
    UE_LOG(LogTemp, Display, TEXT("Name Enemy %s"), *Enemy->GetName());
    FDamageEvent d;
    d.DamageTypeClass = UDamageType::StaticClass();
    Enemy->TakeDamage(20.0f, d, Pawn->GetController(), Pawn);
    // UGameplayStatics::ApplyDamage(Enemy, 20.0f, Pawn->GetController(), Pawn, DamageType);

    UE_LOG(LogTemp, Display, TEXT("DamageGive"));
    Pawn->SetPhaseActionInProgress(false);
    EndAnimatoinAnimNotify->OnEndAnimation.Clear();
}
