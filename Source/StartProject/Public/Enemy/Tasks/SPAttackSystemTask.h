// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GameFramework/DamageType.h"
#include "SPAttackSystemTask.generated.h"

class ASPEnemyCharacter;
class UBlackboardComponent;
class USPEndAnimatoinAnimNotify;
class AAIController;
class ASPBaseCharacter;
class USPHealthAIAComponent;
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
    UPROPERTY()
    UBlackboardComponent* BBComponent;
    UPROPERTY()
    USPEndAnimatoinAnimNotify* EndAnimatoinAnimNotify;
    UPROPERTY()
    AAIController* Controller;
    UPROPERTY()
    ASPBaseCharacter* FocusActor;

    FTimerHandle TimerHandle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
    TSubclassOf<UDamageType> DamageType;

    UPROPERTY()
    USPHealthAIAComponent* HealthComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Phase1")
    TSubclassOf<AActor> SpellPhase1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
    FName FocusKeyName = "EnemyActor";


    void InitActionPhase1();
    void InitActionPhase2();

    void HalfPhase2();

    void EndPhaseOne();
    void EndPhaseTwo();
};
