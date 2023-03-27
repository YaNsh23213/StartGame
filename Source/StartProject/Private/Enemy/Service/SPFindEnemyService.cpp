// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Service/SPFindEnemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Enemy/SPAIPerceptionComponent.h"

USPFindEnemyService::USPFindEnemyService()
{
    NodeName = "Find Enemy";
}

void USPFindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    const auto BlackBoard = OwnerComp.GetBlackboardComponent();
    if (BlackBoard)
    {
        const auto Controller = OwnerComp.GetAIOwner();
        auto Component = Controller->FindComponentByClass<USPAIPerceptionComponent>();
        if (Component)
        {
            BlackBoard->SetValueAsObject(EnemyKey.SelectedKeyName, Component->GetEnemyActor());
        }
    }
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
