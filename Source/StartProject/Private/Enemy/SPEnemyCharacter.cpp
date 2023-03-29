// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPAIPerceptionComponent.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "AIController.h"

ASPEnemyCharacter::ASPEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
    HealthAIAComponent = CreateDefaultSubobject<USPHealthAIAComponent>("HealthAIAComponent");
}

void ASPEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
    if (HealthAIAComponent)
    {
        HealthAIAComponent->OnAIDeath.AddUObject(this, &ASPEnemyCharacter::DeadAnim);
    }
	
}

void ASPEnemyCharacter::DeadAnim() 
{
    PlayAnimMontage(DeathAnimMontage);
    const auto AIController = Cast<AAIController>(GetController());
    AIController->StopMovement();
}

void ASPEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASPEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

