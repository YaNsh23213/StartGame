// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Skills/SPSlotSkillWidget.h"
#include "SPBottomBarSkillsWidget.generated.h"

class UImage;
class UTextBlock;
class UHorizontalBox;
UCLASS()
class STARTPROJECT_API USPBottomBarSkillsWidget : public UUserWidget
{
	GENERATED_BODY()
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* SkillBox;

    UPROPERTY()
    TArray<USPSlotSkillWidget*> ArraySkill;

    void OnSkillSelected(const FBottomSlotActionInfo& Data);
    void InitSkills();
	
};
