// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SPHealthAIAComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAIDeath);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnAIHealthChanged, float);
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STARTPROJECT_API USPHealthAIAComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USPHealthAIAComponent();

    FOnAIDeath OnAIDeath;
    FOnAIHealthChanged OnAIHealthChanged;

    UFUNCTION(BlueprintCallable)
    bool IsDead() const { return CurrentHealth <= 0.0f; }

    UFUNCTION(BlueprintCallable)
    float GetHealthPercent();

    float GetCurrentHealth() { return CurrentHealth; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth;

    UPROPERTY()
    float CurrentHealth;

private:
    UFUNCTION()
    void OnTakeAnyDamage(
        AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
