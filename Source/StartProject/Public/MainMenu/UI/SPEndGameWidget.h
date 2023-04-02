// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPEndGameWidget.generated.h"

class UButton;
UCLASS()
class STARTPROJECT_API USPEndGameWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton* MainMenuBtn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
    FString Level;

private:
    UFUNCTION()
    void NewGame();
};
