// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/SPHealthBarWidget.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "Components/ProgressBar.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Component/SPHealthComponent.h"

void USPHealthBarWidget::NativeOnInitialized()
{
}

void USPHealthBarWidget::InitEmenyHP()
{
    const auto Player = Cast<ASPBaseCharacter>(GetOwningPlayer()->GetPawn());
    if (Player)
    {
        const auto Enemy = Cast<ASPEnemyCharacter>(Player->GetEnemyActor());
        if (Enemy)
        {
            const auto Component = Enemy->FindComponentByClass<USPHealthAIAComponent>();
            if (Component)
            {
                Component->OnAIHealthChanged.AddUObject(this, &USPHealthBarWidget::UpdateHealth);
            }
        }
    }
    UpdateHealth(0);
}

void USPHealthBarWidget::UpdateHealth(float Value)
{
    UE_LOG(LogTemp, Display, TEXT("Update Health"))
    if (HP)
    {
        UE_LOG(LogTemp, Display, TEXT("Update Health1"))
        const auto Player = Cast<ASPBaseCharacter>(GetOwningPlayer()->GetPawn());
        if (Player)
        {
            UE_LOG(LogTemp, Display, TEXT("Update Health2"))
            const auto Enemy = Cast<ASPEnemyCharacter>(Player->GetEnemyActor());
            if (Enemy)
            {
                UE_LOG(LogTemp, Display, TEXT("Update Health3"))
                const auto Component = Enemy->FindComponentByClass<USPHealthAIAComponent>();
                if (Component)
                {
                    UE_LOG(LogTemp, Display, TEXT("New Percent %f"), Component->GetHealthPercent())
                    HP->SetPercent(Component->GetHealthPercent());
                }
            }
        }
    }
}
