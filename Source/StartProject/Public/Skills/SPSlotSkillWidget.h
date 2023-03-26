// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Skills/Spells/STBaseSpellActor.h"
#include "SPSlotSkillWidget.generated.h"

USTRUCT(BlueprintType)
struct FBottomSlotActionInfo
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionInfo")
    UTexture2D* ImageSkill;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionInfo")
    TSubclassOf<ASTBaseSpellActor> Spell;

    // Need more info from Action
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnSkillSelectedSignature, const FBottomSlotActionInfo&);

class UImage;
class UTextBlock;
class UButton;
UCLASS()
class STARTPROJECT_API USPSlotSkillWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    FOnSkillSelectedSignature OnSkillSelected;

    FBottomSlotActionInfo GetFBottomSlotActionInfo() const { return BottomSlotActionInfo; }
    void SetFBottomSlotActionInfo(FBottomSlotActionInfo Data) { BottomSlotActionInfo = Data; }

protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UImage* ActionImage;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ActionKey;

    UPROPERTY(meta = (BindWidget))
    UButton* ActionButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
    FBottomSlotActionInfo BottomSlotActionInfo;

    UFUNCTION()
    void OnGenderItemClicked();
	
};
