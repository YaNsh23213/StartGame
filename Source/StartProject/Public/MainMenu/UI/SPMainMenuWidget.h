// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPMainMenuWidget.generated.h"
DECLARE_MULTICAST_DELEGATE(FOnNewGame);
DECLARE_MULTICAST_DELEGATE(FOnLoadGame);

class UButton;
UCLASS()
class STARTPROJECT_API USPMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton* NewGame;

    UPROPERTY(meta = (BindWidget))
    UButton* LoadGame;

    UPROPERTY(meta = (BindWidget))
    UButton* Options;

    UPROPERTY(meta = (BindWidget))
    UButton* ExitGame;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
    FString Level;

private:
    UFUNCTION(BlueprintCallable, Category = "MyDelegate")
    void OnNewStartGame();

    UFUNCTION(BlueprintCallable, Category = "MyDelegate")
    void OnLoadStartGame();

    UFUNCTION()
    void Exit();

    void OpenNewLevel();

public:
    FOnNewGame NewGameDel;
    FOnLoadGame LoadGameDel;
};
