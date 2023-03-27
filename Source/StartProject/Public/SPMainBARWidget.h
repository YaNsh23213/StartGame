// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPMainBARWidget.generated.h"

class UProgressBar;
UCLASS()
class STARTPROJECT_API USPMainBARWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* HP;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* XP;

    private:
    UFUNCTION()
    void UpdateHealth(float Value);
	
};
