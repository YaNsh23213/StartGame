// Fill out your copyright notice in the Description page of Project Settings.


#include "Skills/SPBottomBarSkillsWidget.h"
#include "Player/SPBaseCharacter.h"
#include "Components/HorizontalBox.h"
#include "Skills/SPSlotSkillWidget.h"
#include "Player/Components/SPSkillsComponent.h"

void USPBottomBarSkillsWidget::NativeOnInitialized()
{
    if (SkillBox)
    {
        TArray<UWidget*> ChildrenWidgets = SkillBox->GetAllChildren();
        for (int32 i = 0; i < ChildrenWidgets.Num(); i++)
        {
            UWidget* ChildWidget = ChildrenWidgets[i];
            UE_LOG(LogTemp, Warning, TEXT("Name %s"), *ChildWidget->GetName());
            const auto ElementArray = Cast<USPSlotSkillWidget>(ChildWidget);
            ArraySkill.Add(ElementArray);
        }
    }
    const auto Player = Cast<ASPBaseCharacter>(GetOwningPlayerPawn());
    if (Player)
    {
        const auto Component = Player->FindComponentByClass<USPSkillsComponent>();
        if (Component)
        {
            Component->SetArraySkillBottomBar(ArraySkill);
        }
    }
    InitSkills();
    Super::NativeOnInitialized();
}

void USPBottomBarSkillsWidget::OnSkillSelected(const FBottomSlotActionInfo& Data)
{
    const auto Player = Cast<ASPBaseCharacter>(GetOwningPlayerPawn());
    if (!Player) return;
    const auto Component = Player->FindComponentByClass<USPSkillsComponent>();
    if (!Component) return;
    Component->SetFBottomSlotActionInfo(Data);
}

void USPBottomBarSkillsWidget::InitSkills()
{
    for (auto Element : ArraySkill)
    {
        Element->OnSkillSelected.AddUObject(this, &USPBottomBarSkillsWidget::OnSkillSelected);
    }
}
