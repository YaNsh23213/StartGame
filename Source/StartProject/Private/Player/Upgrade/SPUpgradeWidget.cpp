// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/Upgrade/SPUpgradeWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Components/SPSkillsComponent.h"
#include "Components/TextBlock.h"
#include "Player/Components/SPBSComponent.h"
#include "Skills/SPBottomBarSkillsWidget.h"

void USPUpgradeWidget::NativeOnInitialized()
{
    const auto PlayerController = GetOwningPlayer();
    const auto Pawn = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    if (!Pawn) return;
    const auto BSComponent = Pawn->FindComponentByClass<USPBSComponent>();
    if (!BSComponent) return;
    const auto SkillsComponent = Pawn->FindComponentByClass<USPSkillsComponent>();
    if (!SkillsComponent) return;
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
    if (CloseBtn)
    {
        CloseBtn->OnClicked.AddDynamic(this, &USPUpgradeWidget::Close);
    }
    if (UpgradePoint)
    {
        auto Point = BSComponent->GetUpgradePoint();
        UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
    }
    if (LVLSlot1)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[0];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot1->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot2)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[1];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot2->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot3)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[2];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot3->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot4)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[3];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot4->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot5)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[4];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot5->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot6)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[5];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot6->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot7)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[6];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot7->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot8)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[7];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot8->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot9)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[8];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot9->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot10)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[9];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot10->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (LVLSlot11)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[10];
        auto Element = Widget->GetFBottomSlotActionInfo();
        LVLSlot11->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
    }
    if (ImageLVL1)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[0];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL1->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL1->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL1->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL2)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[1];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL2->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL2->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL2->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL3)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[2];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL3->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL3->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL3->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL4)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[3];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL4->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL4->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL4->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL5)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[4];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL5->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL5->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL5->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL6)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[5];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL6->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL6->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL6->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL7)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[6];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL7->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL7->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL7->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL8)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[7];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL8->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL8->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL8->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL9)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[8];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL9->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL9->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL9->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL10)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[9];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL10->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL10->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL10->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
    }
    if (ImageLVL11)
    {
        auto Widget = SkillsComponent->GetArraySkillBottomBar()[10];
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL == 1)
        {
            ImageLVL11->SetBrushFromSoftTexture(Element.ImageSkill_1);
        }
        else if (Element.CurrentLVL == 2)
        {
            ImageLVL11->SetBrushFromSoftTexture(Element.ImageSkill_2);
        }
        else if (Element.CurrentLVL == 3)
        {
            ImageLVL11->SetBrushFromSoftTexture(Element.ImageSkill_3);
        }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot1->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL1->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL1->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL1->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot2->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL2->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL2->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL2->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[2];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot3->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL3->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL3->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL3->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot4->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL4->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL4->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL4->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot5->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL5->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL5->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL5->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot6->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL6->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL6->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL6->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
    const auto Widget = SkillsComponent->GetArraySkillBottomBar()[6];
    if (Widget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot7->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL7->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL7->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL7->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot8->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL8->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL8->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL8->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot9->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL9->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL9->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL9->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
                auto BottomBar = Cast<USPBottomBarSkillsWidget>(Pawn->GetBottomWidgwet());
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot10->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL10->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL10->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL10->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
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
        UE_LOG(LogTemp, Warning, TEXT("Try Upgrade"));
        auto Element = Widget->GetFBottomSlotActionInfo();
        if (Element.CurrentLVL > 0 && Element.CurrentLVL < 3)
        {
            auto Point = BSComponent->GetUpgradePoint();
            if (Point > 0)
            {
                Element.CurrentLVL = Element.CurrentLVL + 1;
                Widget->SetFBottomSlotActionInfo(Element);
                Widget->Update();
                Point = Point - 1;
                BSComponent->SetUpgradePoint(-1);
                UpgradePoint->SetText(FText::FromString(FString::FromInt(Point)));
                LVLSlot11->SetText(FText::FromString(FString::FromInt(Element.CurrentLVL)));
                if (Element.CurrentLVL == 1)
                {
                    ImageLVL11->SetBrushFromSoftTexture(Element.ImageSkill_1);
                }
                else if (Element.CurrentLVL == 2)
                {
                    ImageLVL11->SetBrushFromSoftTexture(Element.ImageSkill_2);
                }
                else if (Element.CurrentLVL == 3)
                {
                    ImageLVL11->SetBrushFromSoftTexture(Element.ImageSkill_3);
                }
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Cant Upgrade"));
        }
    }
}

void USPUpgradeWidget::Close()
{
    auto PlayerController = GetOwningPlayer();
    if (PlayerController)
    {
        FInputModeGameOnly Game;
        PlayerController->SetInputMode(Game);
        PlayerController->bShowMouseCursor = false;
    }
    const auto Owner = Cast<ASPBaseCharacter>(PlayerController->GetPawn());
    Owner->Interact();
    this->RemoveFromViewport();
}
