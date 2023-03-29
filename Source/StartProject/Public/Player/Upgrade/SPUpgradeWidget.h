// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPUpgradeWidget.generated.h"

class UButton;
class UTextBlock;
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
    UTextBlock* UpgradePoint;

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

};
