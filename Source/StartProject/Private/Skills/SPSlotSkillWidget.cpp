// Fill out your copyright notice in the Description page of Project Settings.


#include "Skills/SPSlotSkillWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"

void USPSlotSkillWidget::NativeOnInitialized()
{
    if (ActionButton)
    {
        ActionButton->OnClicked.AddDynamic(this, &USPSlotSkillWidget::OnGenderItemClicked);
    }
    if (ActionImage)
    {
        ActionImage->SetBrushFromSoftTexture(BottomSlotActionInfo.ImageSkill);
    }
    Super::NativeOnInitialized();
}

void USPSlotSkillWidget::OnGenderItemClicked()
{
    OnSkillSelected.Broadcast(BottomSlotActionInfo);
}
