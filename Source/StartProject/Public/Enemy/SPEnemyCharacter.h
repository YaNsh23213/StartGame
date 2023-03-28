// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SPEnemyCharacter.generated.h"
class USPAIPerceptionComponent;
class USPHealthAIAComponent;
class UAnimMontage;
UCLASS()
class STARTPROJECT_API ASPEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASPEnemyCharacter();

    bool GetPhaseActionInProgress() { return PhaseActionInProgress; }
    void SetPhaseActionInProgress(bool Value) { PhaseActionInProgress = Value; }

    UAnimMontage* GetAnimMontagePhase1() { return AnimMontagePhase1; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    USPAIPerceptionComponent* AIPerceptionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    USPHealthAIAComponent* HealthAIAComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Phase1")
    UAnimMontage* AnimMontagePhase1;

    bool PhaseActionInProgress = false;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
