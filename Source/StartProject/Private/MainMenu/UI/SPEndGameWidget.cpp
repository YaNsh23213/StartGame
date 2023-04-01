// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/UI/SPEndGameWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USPEndGameWidget::NativeOnInitialized()
{
    if (MainMenuBtn)
    {
        MainMenuBtn->OnClicked.AddDynamic(this, &USPEndGameWidget::NewGame);
    }
}

void USPEndGameWidget::NewGame()
{
    UGameplayStatics::SetGamePaused(GetWorld(), false);
    auto PlayerController = GetOwningPlayer();
    if (PlayerController)
    {
        FInputModeGameOnly Game;
        PlayerController->SetInputMode(Game);
        PlayerController->bShowMouseCursor = false;
    }
    UGameplayStatics::OpenLevel(GetWorld(), *Level, true);
}
