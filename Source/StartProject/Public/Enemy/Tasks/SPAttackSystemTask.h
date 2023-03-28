// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SPAttackSystemTask.generated.h"

class ASPEnemyCharacter;
UCLASS()
class STARTPROJECT_API USPAttackSystemTask : public UBTTaskNode
{
    GENERATED_BODY()
public:
    USPAttackSystemTask();
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

protected:

    UPROPERTY()
    ASPEnemyCharacter* Pawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Phase1")
    TSubclassOf<AActor> SpellPhase1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
    FName FocusKeyName = "EnemyActor";

    void InitActionPhase1();
    void EndPhaseOne();
};
