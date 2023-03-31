// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPHealBoostWidget.generated.h"

class UTextBlock;
UCLASS()
class STARTPROJECT_API USPHealBoostWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    int32 GetAmountHeal() { return AmountHeal; }
    int32 GetAmountBoost() { return AmountBoost; }
    void SetAmountBoost(int32 Amount) { AmountBoost = Amount; }
    void SetAmountHeal(int32 Amount) { AmountHeal = Amount; }

    void HealUpdate(FText Text);
    void BoostUdate(FText Text);

protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Heal;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Boost;

    UPROPERTY(EditAnywhere, Category = "Widget")
    int32 AmountHeal = 2;

    UPROPERTY(EditAnywhere, Category = "Widget")
    int32 AmountBoost = 2;

private:
};
