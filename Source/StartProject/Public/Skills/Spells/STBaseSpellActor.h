// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STBaseSpellActor.generated.h"

UCLASS()
class STARTPROJECT_API ASTBaseSpellActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTBaseSpellActor();

	virtual void StartAction(AActor* OwnerActor);

protected:
	virtual void BeginPlay() override;


};
