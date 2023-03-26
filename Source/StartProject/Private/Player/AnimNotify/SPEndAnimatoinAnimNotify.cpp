// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AnimNotify/SPEndAnimatoinAnimNotify.h"

void USPEndAnimatoinAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnEndAnimation.Broadcast();
    Super::Notify(MeshComp, Animation);
}
