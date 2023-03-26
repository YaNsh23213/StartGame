// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SPEndAnimatoinAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnEndAnimationSignature)

UCLASS()
class STARTPROJECT_API USPEndAnimatoinAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
public:
    virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

    FOnEndAnimationSignature OnEndAnimation;
};
