// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AnimNotify/SPSpawnProjectileAnimNotify.h"

void USPSpawnProjectileAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnSpawnProjectile.Broadcast();
    Super::Notify(MeshComp, Animation);
}
