// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPAIPerceptionComponent.h"

ASPEnemyCharacter::ASPEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASPEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASPEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASPEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

