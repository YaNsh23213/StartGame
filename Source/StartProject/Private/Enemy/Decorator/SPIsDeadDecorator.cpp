// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Decorator/SPIsDeadDecorator.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "AIController.h"

bool USPIsDeadDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto AIController = OwnerComp.GetAIOwner();
    const auto BBComponent = OwnerComp.GetBlackboardComponent();
    if (!AIController || !BBComponent) return false;
    const auto Pawn = Cast<ASPEnemyCharacter>(AIController->GetPawn());
    if (!Pawn) return false;
    const auto Component = Pawn->FindComponentByClass<USPHealthAIAComponent>();
    if (!Component) return false;
    if (Component->IsDead())
    {
        UE_LOG(LogTemp, Warning, TEXT("Return True"));
        return true;
    }
    UE_LOG(LogTemp, Warning, TEXT("Return False"));
    return false;
}
