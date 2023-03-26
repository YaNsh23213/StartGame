// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SPSpawnProjectileAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnSpawnProjectileSignature)
UCLASS()
class STARTPROJECT_API USPSpawnProjectileAnimNotify : public UAnimNotify
{
    GENERATED_BODY()
public:
    virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

    FOnSpawnProjectileSignature OnSpawnProjectile;
};
