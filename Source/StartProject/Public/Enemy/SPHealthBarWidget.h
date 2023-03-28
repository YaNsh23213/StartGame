// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPHealthBarWidget.generated.h"

class UProgressBar;
UCLASS()
class STARTPROJECT_API USPHealthBarWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    void InitEmenyHP();
    UFUNCTION()
    void UpdateHealth(float Value);

protected:
    virtual void NativeOnInitialized() override;
    UPROPERTY(meta = (BindWidget))
    UProgressBar* HP;
};
