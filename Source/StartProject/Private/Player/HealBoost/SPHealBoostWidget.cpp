// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HealBoost/SPHealBoostWidget.h"
#include "Components/TextBlock.h"

void USPHealBoostWidget::NativeOnInitialized()
{
    if (Heal)
    {
        Heal->SetText(FText::FromString(FString::FromInt(AmountHeal)));
    }
    if (Boost)
    {
        Boost->SetText(FText::FromString(FString::FromInt(AmountBoost)));
    }
}

void USPHealBoostWidget::HealUpdate(FText Text)
{
    if (Heal)
    {
        Heal->SetText(Text);
    }
}

void USPHealBoostWidget::BoostUdate(FText Text)
{
    if (Boost)
    {
        Boost->SetText(Text);
    }
}
