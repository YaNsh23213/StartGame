// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPAlchemistShopWidget.generated.h"

class UButton;
class UTextBlock;
class ASPBaseCharacter;
class USPBSComponent;
class USPHealBoostWidget;
UCLASS()
class STARTPROJECT_API USPAlchemistShopWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton* HealPotion;
    UPROPERTY(meta = (BindWidget))
    UButton* ArmorPotion;
    UPROPERTY(meta = (BindWidget))
    UButton* CloseButton;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* UpgradePoint;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* AmountHeal;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* AmountArmor;

    UPROPERTY()
    ASPBaseCharacter* Owner;
    UPROPERTY()
    USPBSComponent* BSComponent;
    UPROPERTY()
    USPHealBoostWidget* Widget;

private:
    UFUNCTION()
    void UpgradeHealPotion();
    UFUNCTION()
    void UpgradeArmorPotion();
};
