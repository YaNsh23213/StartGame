// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Skills/SPSlotSkillWidget.h"
#include "SPSkillsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTPROJECT_API USPSkillsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USPSkillsComponent();

    FBottomSlotActionInfo GetFBottomSlotActionInfo() const { return BottomSlotActionInfo; }
    void SetFBottomSlotActionInfo(FBottomSlotActionInfo Data);

    TArray<USPSlotSkillWidget*> GetArraySkillBottomBar() const { return ArraySkillBottomBar; }
    void SetArraySkillBottomBar(const TArray<USPSlotSkillWidget*> Array) { ArraySkillBottomBar = Array; }

    bool GetCanCast() const { return CanCast; }
    void SetCanCast(bool Amount)
    {
        CanCast = Amount;
        if (CanCast == true)
        {
            UE_LOG(LogTemp, Warning, TEXT("Change CanCast on true"));
        }
        if (CanCast == false)
        {
            UE_LOG(LogTemp, Warning, TEXT("Change CanCast on false"));
        }
    }

    bool GetCastInProgress() const { return CastInProgress; }
    void SetCastInProgress(const bool Amount) { CastInProgress = Amount; }

    int32 GetLevelCast() const { return LevelCast; }
    void SetLevelCast(const int32 Amount) { LevelCast = Amount; }

    void StartAction(FBottomSlotActionInfo Data);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "DataSpell")
    FBottomSlotActionInfo BottomSlotActionInfo;

    UPROPERTY()
    TArray<USPSlotSkillWidget*> ArraySkillBottomBar;

    UPROPERTY()
    bool CanCast = true;

    UPROPERTY()
    int32 LevelCast = 1;

private:
    bool CastInProgress = false;

};
