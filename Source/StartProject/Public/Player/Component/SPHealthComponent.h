// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SPHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged,float);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTPROJECT_API USPHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USPHealthComponent();

    FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;

    UFUNCTION()
    bool IsDead() const { return CurrentHealth <= 0.0f; }

    UFUNCTION(BlueprintCallable)
    float GetHealthPercent();

    float GetCurrentHealth() { return CurrentHealth; }

    float GetArmorModifier() { return ArmorModifier; }
    void SetArmorModifier(float Amount) { ArmorModifier = Amount; }

    void HealUp(float Amount);

protected:
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth;

	UPROPERTY()
    float CurrentHealth;

    UPROPERTY()
    float ArmorModifier=0;

private:
    UFUNCTION()
    void OnTakeAnyDamage(
        AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
