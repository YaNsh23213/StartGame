// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SPEnemyCharacter.generated.h"
class USPAIPerceptionComponent;
UCLASS()
class STARTPROJECT_API ASPEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASPEnemyCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
    USPAIPerceptionComponent* AIPerceptionComponent;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
