// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu/UI/SPPauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USPPauseWidget::NativeOnInitialized()
{
    if (MainMenuBtn)
    {
        MainMenuBtn->OnClicked.AddDynamic(this, &USPPauseWidget::MainMenuAction);
    }
    if (ClosePause)
    {
        ClosePause->OnClicked.AddDynamic(this, &USPPauseWidget::ClosePauseAction);
    }
}

void USPPauseWidget::MainMenuAction()
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

void USPPauseWidget::ClosePauseAction()
{
    UGameplayStatics::SetGamePaused(GetWorld(), false);
    auto PlayerController = GetOwningPlayer();
    if (PlayerController)
    {
        FInputModeGameOnly Game;
        PlayerController->SetInputMode(Game);
        PlayerController->bShowMouseCursor = false;
    }
    this->RemoveFromViewport();
}
