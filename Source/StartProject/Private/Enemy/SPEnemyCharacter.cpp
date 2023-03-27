// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPAIPerceptionComponent.h"
#include "Enemy/SPHealthAIAComponent.h"

ASPEnemyCharacter::ASPEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
    HealthAIAComponent = CreateDefaultSubobject<USPHealthAIAComponent>("HealthAIAComponent");
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

