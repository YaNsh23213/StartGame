// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SPAIPerceptionComponent.h"
#include"AIController.h"
#include"Perception/AISense_Sight.h"

AActor* USPAIPerceptionComponent::GetEnemyActor() const
{
    TArray<AActor*> ArrayActors;
    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), ArrayActors);
    if (ArrayActors.Num() != 0)
    {
        for (auto Actor : ArrayActors)
        {
            return Actor;
        }
    }
    if (EnemyActorPC != nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("Set in preceprion component %s"), *EnemyActorPC->GetName());
        return EnemyActorPC;
    }
    return nullptr;
}
