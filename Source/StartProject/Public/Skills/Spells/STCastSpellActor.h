// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skills/Spells/STBaseSpellActor.h"
#include "STCastSpellActor.generated.h"

UCLASS()
class STARTPROJECT_API ASTCastSpellActor : public ASTBaseSpellActor
{
    GENERATED_BODY()
protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "DataSpell")
    UDamageType* DamageType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "DataSpell")
    UAnimMontage* AnimMontage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellLvL")
    TSubclassOf<AActor> Spell_1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellLvL")
    TSubclassOf<AActor> Spell_2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellLvL")
    TSubclassOf<AActor> Spell_3;

    UPROPERTY()
    int32 LevelSpel;

public:
    virtual void StartAction(AActor* OwnerActor) override;

private:
    void InitAnimations();
    void SpawnProjectile();
    void EndAnimation();

    UPROPERTY()
    AActor* CurrentOwner;
};
