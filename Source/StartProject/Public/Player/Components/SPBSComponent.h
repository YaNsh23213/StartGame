// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SPBSComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTPROJECT_API USPBSComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USPBSComponent();
    UFUNCTION(BlueprintCallable, Category = "BS")
    bool GetBSActive() { return BSActive; }
    UFUNCTION(BlueprintCallable, Category = "BS")
    void SetBSActive(bool Value) { BSActive = Value; }

protected:
	virtual void BeginPlay() override;

	bool BSActive = false;

};
