// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu/UI/SPMainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"
#include "MainMenu/SPPathLineActor.h"

void USPMainMenuWidget::NativeOnInitialized()
{
    if (NewGame)
    {
        NewGame->OnClicked.AddDynamic(this, &USPMainMenuWidget::OnNewStartGame);
    }
    if (LoadGame)
    {
        LoadGame->OnClicked.AddDynamic(this, &USPMainMenuWidget::OnLoadStartGame);
    }
    if (ExitGame)
    {
        ExitGame->OnClicked.AddDynamic(this, &USPMainMenuWidget::Exit);
    }
}

void USPMainMenuWidget::OnNewStartGame()
{
    UE_LOG(LogTemp, Display, TEXT("Click"))
    TSubclassOf<AActor> ClassToFind;
    ClassToFind = AActor::StaticClass();
    TArray<AActor*> FoundPath;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundPath);
    for (auto Element : FoundPath)
    {
        UE_LOG(LogTemp, Display, TEXT("CheckNew %s"), *Element->GetName())
        if (Element->GetName() == TEXT("BP_StartNewGameActor_C_1"))
        {
            auto Path = Cast<ASPPathLineActor>(Element);
            if (Path)
            {
                Path->LoadGameProgress();
                this->RemoveFromViewport();
                FTimerHandle TimerHandle;
                GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &USPMainMenuWidget::OpenNewLevel, 3.0f, false);

            }
            UE_LOG(LogTemp, Display, TEXT("FindTraectory"));
        }
    }
}

void USPMainMenuWidget::OnLoadStartGame()
{
    UE_LOG(LogTemp, Display, TEXT("Click"))
    TSubclassOf<AActor> ClassToFind;
    ClassToFind = AActor::StaticClass();
    TArray<AActor*> FoundPath;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundPath);
    for (auto Element : FoundPath)
    {
        UE_LOG(LogTemp, Display, TEXT("CheckNew %s"), *Element->GetName())
        if (Element->GetName() == TEXT("BP_Traectory_C_1"))
        {
            auto Path = Cast<ASPPathLineActor>(Element);
            if (Path)
            {
                Path->LoadGameProgress();
                this->RemoveFromViewport();
            }
            UE_LOG(LogTemp, Display, TEXT("FindTraectory"));
        }
    }
}

void USPMainMenuWidget::Exit() {}

void USPMainMenuWidget::OpenNewLevel() 
{
    UGameplayStatics::OpenLevel(GetWorld(), *Level, true);
}
