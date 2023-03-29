// Fill out your copyright notice in the Description page of Project Settings.


#include "Skills/Spells/STBaseSpellActor.h"

ASTBaseSpellActor::ASTBaseSpellActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASTBaseSpellActor::StartAction(AActor* OwnerActor,int32 LVLCast)
{
    UE_LOG(LogTemp, Warning, TEXT("Base spell activated"))
}

void ASTBaseSpellActor::BeginPlay()
{
	Super::BeginPlay();
	
}

