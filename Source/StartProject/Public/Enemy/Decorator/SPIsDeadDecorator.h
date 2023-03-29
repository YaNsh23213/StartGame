// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "SPIsDeadDecorator.generated.h"

/**
 * 
 */
UCLASS()
class STARTPROJECT_API USPIsDeadDecorator : public UBTDecorator
{
	GENERATED_BODY()
protected:
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
	
};
