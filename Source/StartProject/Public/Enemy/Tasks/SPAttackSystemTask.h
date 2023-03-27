// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SPAttackSystemTask.generated.h"

/**
 * 
 */
UCLASS()
class STARTPROJECT_API USPAttackSystemTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
    USPAttackSystemTask();
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory); 

protected:

};
