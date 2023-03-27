// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SPAIDragController.generated.h"

class USPAIPerceptionComponent;
UCLASS()
class STARTPROJECT_API ASPAIDragController : public AAIController
{
	GENERATED_BODY()
public:
    ASPAIDragController();

    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Level")
    USPAIPerceptionComponent* AIPerceptionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
    FName FocusKeyName = "EnemyActor";

    private:
    AActor* GetFocusOnActor() const;
	
};
