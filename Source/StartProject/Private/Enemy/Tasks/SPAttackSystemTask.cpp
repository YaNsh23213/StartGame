// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Tasks/SPAttackSystemTask.h"
#include "AIController.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPHealthAIAComponent.h"

USPAttackSystemTask::USPAttackSystemTask() {}

EBTNodeResult::Type USPAttackSystemTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto BlackBoard = OwnerComp.GetBlackboardComponent();
    if (!Controller || !BlackBoard) return EBTNodeResult::Failed;

    const auto Pawn = Cast<ASPEnemyCharacter>(Controller->GetPawn());
    if (!Pawn) return EBTNodeResult::Failed;

    const auto Component = Pawn->FindComponentByClass<USPHealthAIAComponent>();
    if (!Component) return EBTNodeResult::Failed;

    auto CurrentHealth = Component->GetCurrentHealth();
    if (CurrentHealth > 80 && CurrentHealth <= 100)
    {
        UE_LOG(LogTemp, Display, TEXT("Phase 1 HP %f"), CurrentHealth);
    }
    return EBTNodeResult::Type();
}
