// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Components/SPSkillsComponent.h"
#include "Skills/SPSlotSkillWidget.h"

USPSkillsComponent::USPSkillsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void USPSkillsComponent::SetFBottomSlotActionInfo(FBottomSlotActionInfo Data)
{
    BottomSlotActionInfo = Data;
    if (!Data.Spell) return;
    UE_LOG(LogTemp, Warning, TEXT("Name Skill %s"), *BottomSlotActionInfo.Spell->GetName());
    if (CanCast == true)
    {
        StartAction(Data);
    }
}
void USPSkillsComponent::StartAction(FBottomSlotActionInfo Data)
{
    if (!Data.Spell) return;
    const auto TActor = NewObject<ASTBaseSpellActor>(this, Data.Spell);
    UE_LOG(LogTemp, Warning, TEXT("Skill StartAction"));
    if (!TActor) return;
    TActor->StartAction(GetOwner());
}
void USPSkillsComponent::BeginPlay()
{
	Super::BeginPlay();
}
