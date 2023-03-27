// Fill out your copyright notice in the Description page of Project Settings.

#include "SPMainBARWidget.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Component/SPHealthComponent.h"
#include "Components/ProgressBar.h"

void USPMainBARWidget::NativeOnInitialized()
{
    const auto Player = Cast<ASPBaseCharacter>(GetOwningPlayer()->GetPawn());
    if (Player)
    {
        const auto Component = Player->FindComponentByClass<USPHealthComponent>();
        if (Component)
        {
            Component->OnHealthChanged.AddUObject(this, &USPMainBARWidget::UpdateHealth);
        }
    }
    UpdateHealth(0);
}

void USPMainBARWidget::UpdateHealth(float Value)
{
    if (HP)
    {
        const auto Player = Cast<ASPBaseCharacter>(GetOwningPlayer()->GetPawn());
        if (Player)
        {
            const auto Component = Player->FindComponentByClass<USPHealthComponent>();
            if (Component)
            {
                HP->SetPercent(Component->GetHealthPercent());
            }
        }
    }
}
