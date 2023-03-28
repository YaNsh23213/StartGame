// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/EngineTypes.h"
#include "SPBaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USPSkillsComponent;
class USPBSComponent;
class USPHealthComponent;
class UAnimMontage;
UCLASS()
class STARTPROJECT_API ASPBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASPBaseCharacter();

    AActor* GetEnemyActor() { return CurrentEnemy; }
    void SetEnemyActor(AActor* Actor) { CurrentEnemy = Actor; }

    bool GetBSStatus() { return BSStatus; }
    void SetBSStatus(bool Value) { BSStatus = Value; }

    bool GetIsEnemyWidgwetAdded() { return IsEnemyWidgwetAdded; }
    void SetIsEnemyWidgwetAdded(bool Value) { IsEnemyWidgwetAdded = Value; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USPSkillsComponent* SkillsComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USPBSComponent* BSComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USPHealthComponent* HealthComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<AActor> Weapon;

    UPROPERTY(EditAnywhere, Category = "Widget")
    TSubclassOf<UUserWidget> WidgetClass;

    UPROPERTY()
    UUserWidget* WidgetPauseInstance;

    UPROPERTY()
    AActor* CurrentEnemy;

    UPROPERTY(EditAnywhere, Category = "WidgetEnemy")
    TSubclassOf<UUserWidget> WidgetEnemy;

     UPROPERTY()
    UUserWidget* WidgetEnemyInstance;

    UPROPERTY()
    bool BSStatus = false;
    UPROPERTY()
    bool IsEnemyWidgwetAdded = false;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void Turn(float Value);
    void LookUp(float Value);
    UFUNCTION()
    void MoveForward(float Amount);
    UFUNCTION()
    void MoveRight(float Amount);
    UPROPERTY()
    bool InPause = false;

    void SlotAction1();
    void SlotAction2();
    void SlotAction3();
    void SlotAction4();
    void SlotAction5();
    void SlotAction6();
    void SlotAction7();
    void SlotAction8();
    void SlotAction9();
    void SlotAction10();
    void SlotAction11();

    void Pause();
};
