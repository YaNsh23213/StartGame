// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/Upgrade/SPUpgradeWidget.h"
#include "Components/Button.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Components/SPSkillsComponent.h"
#include "Components/TextBlock.h"
#include "Player/Components/SPBSComponent.h"

void USPUpgradeWidget::NativeOnInitialized()
{
    if (Upgrade_1)
    {
        Upgrade_1->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast1);
    }
    if (Upgrade_2)
    {
        Upgrade_2->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast2);
    }
    if (Upgrade_3)
    {
        Upgrade_3->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast3);
    }
    if (Upgrade_4)
    {
        Upgrade_4->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast4);
    }
    if (Upgrade_5)
    {
        Upgrade_5->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast5);
    }
    if (Upgrade_6)
    {
        Upgrade_6->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast6);
    }
    if (Upgrade_7)
    {
        Upgrade_7->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast7);
    }
    if (Upgrade_8)
    {
        Upgrade_8->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast8);
    }
    if (Upgrade_9)
    {
        Upgrade_9->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast9);
    }
    if (Upgrade_10)
    {
        Upgrade_10->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast10);
    }
    if (Upgrade_11)
    {
        Upgrade_11->OnClicked.AddDynamic(this, &USPUpgradeWidget::UpgradeCast11);
    }
    if (UpgradePoint)
    {
        const auto PlayerController = GetOwningPlayer();
        const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
        if (!Pawn) return;
        const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
        if (!BSComponent) return;
        auto Point = BSComponent->GetUpgradePoint();
        UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
    }
}

void USPUpgradeWidget::UpgradeCast1()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[0];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast2()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[1];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }

        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast3()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[3];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast4()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[3];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast5()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[4];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast6()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[5];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast7()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[2];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 6)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast8()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[7];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast9()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[8];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast10()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[9];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
void USPUpgradeWidget::UpgradeCast11()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[10];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Point = Point - 1;
                BSComponent->SetUpgradePoint(Point);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}
