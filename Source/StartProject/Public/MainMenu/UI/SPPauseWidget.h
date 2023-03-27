// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPPauseWidget.generated.h"

class UButton;

UCLASS()
class STARTPROJECT_API USPPauseWidget : public UUserWidget
{
    GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton* MainMenuBtn;

    UPROPERTY(meta = (BindWidget))
    UButton* ClosePause;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
    FString Level;

private:
    UFUNCTION()
    void MainMenuAction();

    UFUNCTION()
    void ClosePauseAction();
};
