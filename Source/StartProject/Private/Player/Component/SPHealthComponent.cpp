// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Component/SPHealthComponent.h"


USPHealthComponent::USPHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

float USPHealthComponent::GetHealthPercent()
{
    return CurrentHealth/MaxHealth;
}

void USPHealthComponent::BeginPlay()
{
	Super::BeginPlay();
    CurrentHealth = MaxHealth;
    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USPHealthComponent::OnTakeAnyDamage);
    }
}

void USPHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead()) return;
    CurrentHealth = FMath::Clamp(CurrentHealth - 0, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(CurrentHealth);
    if (IsDead())
    {
        OnDeath.Broadcast();
    }
}
