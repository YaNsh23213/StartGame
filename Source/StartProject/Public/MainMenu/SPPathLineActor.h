// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "SPPathLineActor.generated.h"
class UCurveFloat;
UCLASS()
class STARTPROJECT_API ASPPathLineActor : public AActor
{
    GENERATED_BODY()

public:
    ASPPathLineActor();

    UFUNCTION()
    void MyTimelineCallback(float Value);

protected:
    virtual void BeginPlay() override;

    FTimeline MyTimeline;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
    UCurveFloat* CurveFloat;

    UPROPERTY()
    FVector StartLocation;

    UPROPERTY()
    FVector EndLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve")
    float ZOffset;

public:
    void LoadGameProgress();
    void Tick(float DeltaTime);
};
