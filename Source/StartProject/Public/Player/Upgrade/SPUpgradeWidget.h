// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPUpgradeWidget.generated.h"

class UButton;
class UTextBlock;
class UImage;
UCLASS()
class STARTPROJECT_API USPUpgradeWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_1;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_2;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_3;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_4;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_5;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_6;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_7;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_8;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_9;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_10;
    UPROPERTY(meta = (BindWidget))
    UButton* Upgrade_11;

    UPROPERTY(meta = (BindWidget))
    UButton* CloseBtn;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* UpgradePoint;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot1;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot2;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot3;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot4;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot5;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot6;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot7;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot8;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot9;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot10;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* LVLSlot11;

    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL1;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL2;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL3;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL4;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL5;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL6;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL7;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL8;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL9;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL10;
    UPROPERTY(meta = (BindWidget))
    UImage* ImageLVL11;

private:
    UFUNCTION()
    void UpgradeCast1();
    UFUNCTION()
    void UpgradeCast2();
    UFUNCTION()
    void UpgradeCast3();
    UFUNCTION()
    void UpgradeCast4();
    UFUNCTION()
    void UpgradeCast5();
    UFUNCTION()
    void UpgradeCast6();
    UFUNCTION()
    void UpgradeCast7();
    UFUNCTION()
    void UpgradeCast8();
    UFUNCTION()
    void UpgradeCast9();
    UFUNCTION()
    void UpgradeCast10();
    UFUNCTION()
    void UpgradeCast11();
    UFUNCTION()
    void Close();

};
