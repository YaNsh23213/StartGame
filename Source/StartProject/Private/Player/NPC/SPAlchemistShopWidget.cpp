// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/NPC/SPAlchemistShopWidget.h"
#include "Components/Button.h"
#include "Player/SPBaseCharacter.h"
#include "Player/HealBoost/SPHealBoostWidget.h"
#include "Player/Components/SPBSComponent.h"
#include "Components/TextBlock.h"

void USPAlchemistShopWidget::NativeOnInitialized()
{
    Owner = Cast<ASPBaseCharacter>(GetOwningPlayerPawn());
    BSComponent = Owner->FindComponentByClass<USPBSComponent>();
    Widget = Cast<USPHealBoostWidget>(Owner->GetHealBoostInstance());
    if (HealPotion)
    {
        HealPotion->OnClicked.AddDynamic(this, &USPAlchemistShopWidget::UpgradeHealPotion);
    }
    if (ArmorPotion)
    {
        ArmorPotion->OnClicked.AddDynamic(this, &USPAlchemistShopWidget::UpgradeArmorPotion);
    }
    if (UpgradePoint)
    {
        auto Point = BSComponent->GetUpgradePoint();
        UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
    }
    if (AmountHeal)
    {
        auto AmountHealPotion = Widget->GetAmountHeal();
        AmountHeal->SetText(FText::FromString(FString::FromInt(AmountHealPotion)));
    }
    if (AmountArmor)
    {
        auto AmountArmorPotion = Widget->GetAmountBoost();
        AmountArmor->SetText(FText::FromString(FString::FromInt(AmountArmorPotion)));
    }
    if (CloseButton)
    {
        CloseButton->OnClicked.AddDynamic(this, &USPAlchemistShopWidget::CloseMenu);
    }
}

void USPAlchemistShopWidget::UpgradeHealPotion()
{
    auto Point = BSComponent->GetUpgradePoint();
    auto AmountHealPotion = Widget->GetAmountHeal();
    if (Point > 0)
    {
        if (Widget)
        {
            AmountHealPotion = AmountHealPotion + 1;
            Point = Point - 1;
            BSComponent->SetUpgradePoint(-1);
            UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            Widget->SetAmountHeal(AmountHealPotion);
            Widget->HealUpdate(FText::FromString(FString::FromInt(AmountHealPotion)));
            AmountHeal->SetText(FText::FromString(FString::FromInt(AmountHealPotion)));
        }
    }
}

void USPAlchemistShopWidget::UpgradeArmorPotion()
{
    auto Point = BSComponent->GetUpgradePoint();
    auto AmountArmorPotion = Widget->GetAmountBoost();
    if (Point > 0)
    {
        if (Widget)
        {
            AmountArmorPotion = AmountArmorPotion + 1;
            Point = Point - 1;
            BSComponent->SetUpgradePoint(-1);
            UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            Widget->SetAmountBoost(AmountArmorPotion);
            Widget->HealUpdate(FText::FromString(FString::FromInt(AmountArmorPotion)));
            AmountArmor->SetText(FText::FromString(FString::FromInt(AmountArmorPotion)));
            
        }
    }
}

void USPAlchemistShopWidget::CloseMenu()
{
    auto PlayerController = GetOwningPlayer();
    if (PlayerController)
    {
        FInputModeGameOnly Game;
        PlayerController->SetInputMode(Game);
        PlayerController->bShowMouseCursor = false;
    }
    Owner->Interact();
    this->RemoveFromViewport();
}
