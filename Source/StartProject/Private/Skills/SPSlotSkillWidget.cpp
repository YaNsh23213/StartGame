// Fill out your copyright notice in the Description page of Project Settings.

#include "Skills/SPSlotSkillWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Components/SPSkillsComponent.h"
#include "Skills/Spells/STCastSpellActor.h"

void USPSlotSkillWidget::NativeOnInitialized()
{
    if (ActionButton)
    {
        ActionButton->OnClicked.AddDynamic(this, &USPSlotSkillWidget::OnGenderItemClicked);
    }
    if (ActionImage)
    {
        auto Player = Cast<ASPBaseCharacter>(GetOwningPlayerPawn());
        UE_LOG(LogTemp, Warning, TEXT("Work 1"))
        if (Player)
        {
            UE_LOG(LogTemp, Warning, TEXT("Work 2"))
            auto Component = Player->FindComponentByClass<USPSkillsComponent>();
            if (Component)
            {
                UE_LOG(LogTemp, Warning, TEXT("Work 3"))
                auto LvLCast = Component->GetLevelCast();
                if (LvLCast == 1)
                {
                    ActionImage->SetBrushFromSoftTexture(BottomSlotActionInfo.ImageSkill_1);
                }
                if (LvLCast == 2)
                {
                    ActionImage->SetBrushFromSoftTexture(BottomSlotActionInfo.ImageSkill_2);
                }
                if (LvLCast == 3)
                {
                    ActionImage->SetBrushFromSoftTexture(BottomSlotActionInfo.ImageSkill_3);
                }
            }
        }
    }
    Super::NativeOnInitialized();
}

void USPSlotSkillWidget::OnGenderItemClicked()
{
    OnSkillSelected.Broadcast(BottomSlotActionInfo);
}
