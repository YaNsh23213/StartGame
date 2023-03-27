// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu/SPPathLineActor.h"
#include "Components/SplineComponent.h"
#include "Components/TimelineComponent.h"
#include "Kismet/GameplayStatics.h"

ASPPathLineActor::ASPPathLineActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASPPathLineActor::BeginPlay()
{
    Super::BeginPlay();
}
void ASPPathLineActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MyTimeline.TickTimeline(DeltaTime);
}

void ASPPathLineActor::MyTimelineCallback(float Value)
{
    UE_LOG(LogTemp, Display, TEXT("Tick %f"), Value);
    auto SplineComponent = FindComponentByClass<USplineComponent>();
    if (SplineComponent)
    {
        auto Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
        FTransform Transform;
        Transform.SetLocation(SplineComponent->GetLocationAtTime(Value, ESplineCoordinateSpace::World));
        Transform.SetRotation(FQuat::MakeFromRotator(SplineComponent->GetRotationAtTime(Value, ESplineCoordinateSpace::World)));
        Player->SetActorTransform(Transform);
    }
}

void ASPPathLineActor::LoadGameProgress()
{

    UTimelineComponent* TimelineComp = NewObject<UTimelineComponent>(this, FName("MyTimeline"));
    MyTimeline.SetTimelineLength(5.0f);
    MyTimeline.SetLooping(false);

    FOnTimelineFloat TimelineCallback;
    TimelineCallback.BindUFunction(this, FName("MyTimelineCallback"));
    MyTimeline.AddInterpFloat(CurveFloat, TimelineCallback);
    MyTimeline.PlayFromStart();
}
