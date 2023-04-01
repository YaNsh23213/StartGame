// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SPHealthAIAComponent.h"
#include "AIController.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPAIDragController.h"
#include "Enemy/SPAIPerceptionComponent.h"

USPHealthAIAComponent::USPHealthAIAComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

float USPHealthAIAComponent::GetHealthPercent()
{
    return CurrentHealth / MaxHealth;
}

void USPHealthAIAComponent::BeginPlay()
{
	Super::BeginPlay();
    CurrentHealth = MaxHealth;
    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USPHealthAIAComponent::OnTakeAnyDamage);
    }
}

void USPHealthAIAComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead()) return;
    CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
    OnAIHealthChanged.Broadcast(CurrentHealth);
    const auto ComponentOwner = Cast<ASPEnemyCharacter>(GetOwner());
    if (ComponentOwner)
    {
        const auto Controller = Cast<ASPAIDragController>(ComponentOwner->GetController());
        if (Controller)
        {
            auto PerceptionController = Controller->FindComponentByClass<USPAIPerceptionComponent>();
            if (PerceptionController)
            {
                PerceptionController->EnemyActorPC = DamageCauser;
                UE_LOG(LogTemp, Display, TEXT("Set in health component %s"), *DamageCauser->GetName());
            }
        }
    }
    if (IsDead())
    {
        OnAIDeath.Broadcast();
    }
}
