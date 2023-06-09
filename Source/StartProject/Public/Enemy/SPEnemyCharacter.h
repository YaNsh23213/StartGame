// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SPEnemyCharacter.generated.h"
class USPAIPerceptionComponent;
class USPHealthAIAComponent;
class UAnimMontage;
class ASPBaseCharacter;
UCLASS()
class STARTPROJECT_API ASPEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASPEnemyCharacter();

    bool GetPhaseActionInProgress() { return PhaseActionInProgress; }
    void SetPhaseActionInProgress(bool Value) { PhaseActionInProgress = Value; }

    UAnimMontage* GetAnimMontagePhase1() { return AnimMontagePhase1; }
    UAnimMontage* GetAnimMontagePhase2() { return AnimMontagePhase2; }

    ASPBaseCharacter* GetPEnemyActor() { return EnemyActor; }
    void SetEnemyActor(ASPBaseCharacter* Value) { EnemyActor = Value; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    USPAIPerceptionComponent* AIPerceptionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    USPHealthAIAComponent* HealthAIAComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Phase1")
    UAnimMontage* AnimMontagePhase1;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Phase1")
    UAnimMontage* AnimMontagePhase2;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Phase1")
    UAnimMontage* DeathAnimMontage;

    bool PhaseActionInProgress = false;

    void DeadAnim();

    void DestroyDeadActor();

    UPROPERTY()
    ASPBaseCharacter* EnemyActor;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
