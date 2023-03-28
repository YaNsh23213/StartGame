// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Tasks/SPAttackSystemTask.h"
#include "AIController.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "Player/AnimNotify/SPEndAnimatoinAnimNotify.h"
#include "BehaviorTree/BlackboardComponent.h"

USPAttackSystemTask::USPAttackSystemTask() {}

EBTNodeResult::Type USPAttackSystemTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto BlackBoard = OwnerComp.GetBlackboardComponent();
    if (!Controller || !BlackBoard) return EBTNodeResult::Failed;

    Pawn = Cast<ASPEnemyCharacter>(Controller->GetPawn());
    if (!Pawn) return EBTNodeResult::Failed;

    const auto Component = Pawn->FindComponentByClass<USPHealthAIAComponent>();
    if (!Component) return EBTNodeResult::Failed;

    auto CurrentHealth = Component->GetCurrentHealth();
    if (CurrentHealth > 80 && CurrentHealth <= 100)
    {
        if (Pawn->GetPhaseActionInProgress() == false)
        {
            UE_LOG(LogTemp, Display, TEXT("Phase 1 HP %f"), CurrentHealth);
            InitActionPhase1();
            Pawn->SetPhaseActionInProgress(true);
            Controller->SetFocus(Cast<AActor>(BlackBoard->GetValueAsObject(FocusKeyName)));
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
        auto EndAnimation = Cast<USPEndAnimatoinAnimNotify>(NotifyEvent.Notify);
      
        if (EndAnimation)
        {
            EndAnimation->OnEndAnimation.AddUObject(this, &USPAttackSystemTask::EndPhaseOne);
        }
    }
}

void USPAttackSystemTask::EndPhaseOne() 
{
    Pawn->SetPhaseActionInProgress(false);
}
