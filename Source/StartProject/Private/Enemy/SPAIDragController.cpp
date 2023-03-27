// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SPAIDragController.h"
#include "Enemy/SPAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ASPAIDragController::ASPAIDragController() 
{
    AIPerceptionComponent = CreateDefaultSubobject<USPAIPerceptionComponent>("AIPerceptionComponent");
    SetPerceptionComponent(*AIPerceptionComponent);
}

void ASPAIDragController::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
    const auto AimActor = GetFocusOnActor();
    if (AimActor)
    {
        UE_LOG(LogTemp, Display, TEXT("FindEnemy %s"), *AimActor->GetName());
    }
}

AActor* ASPAIDragController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;
    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusKeyName));
}
