// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPAIPerceptionComponent.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "AIController.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Components/SPBSComponent.h"

ASPEnemyCharacter::ASPEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    HealthAIAComponent = CreateDefaultSubobject<USPHealthAIAComponent>("HealthAIAComponent");
}

void ASPEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();
    if (HealthAIAComponent)
    {
        HealthAIAComponent->OnAIDeath.AddUObject(this, &ASPEnemyCharacter::DeadAnim);
    }
}

void ASPEnemyCharacter::DeadAnim()
{
    PlayAnimMontage(DeathAnimMontage);
    const auto AIController = Cast<AAIController>(GetController());
    AIController->StopMovement();
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASPEnemyCharacter::DestroyDeadActor, 5.0f, false);
}
void ASPEnemyCharacter::DestroyDeadActor()
{
    if (EnemyActor)
    {
        auto BSComponent = EnemyActor->FindComponentByClass<USPBSComponent>();
        if (BSComponent)
        {
            BSComponent->SetUpgradePoint(1);
            BSComponent->SetBSActive(false);
        }
        EnemyActor->ClearWidgetEnemy();
        EnemyActor->SetBSStatus(false);
        EnemyActor->SetIsEnemyWidgwetAdded(false);
    }
    this->Destroy();
}

void ASPEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASPEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
