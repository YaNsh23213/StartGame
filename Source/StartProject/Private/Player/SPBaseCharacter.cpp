// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/SPBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/Components/SPSkillsComponent.h"

ASPBaseCharacter::ASPBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArmComponent"));
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->bUsePawnControlRotation = true;
    SkillsComponent = CreateDefaultSubobject<USPSkillsComponent>("SkillsComponent");

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp3P"));
    CameraComponent->SetupAttachment(SpringArmComponent);
}

void ASPBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
    if (Weapon)
    {
        FTransform SocketTransform = this->GetMesh()->GetSocketTransform("WeaponSocket");
        AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(Weapon, SocketTransform);
        SpawnedActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "WeaponSocket");
    }
}

void ASPBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
void ASPBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASPBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASPBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &ASPBaseCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &ASPBaseCharacter::LookUp);

    PlayerInputComponent->BindAction("SlotAction_1", IE_Pressed, this, &ASPBaseCharacter::SlotAction1);
    PlayerInputComponent->BindAction("SlotAction_2", IE_Pressed, this, &ASPBaseCharacter::SlotAction2);
    PlayerInputComponent->BindAction("SlotAction_3", IE_Pressed, this, &ASPBaseCharacter::SlotAction3);
    PlayerInputComponent->BindAction("SlotAction_4", IE_Pressed, this, &ASPBaseCharacter::SlotAction4);
    PlayerInputComponent->BindAction("SlotAction_5", IE_Pressed, this, &ASPBaseCharacter::SlotAction5);
    PlayerInputComponent->BindAction("SlotAction_6", IE_Pressed, this, &ASPBaseCharacter::SlotAction6);
    PlayerInputComponent->BindAction("SlotAction_7", IE_Pressed, this, &ASPBaseCharacter::SlotAction7);
    PlayerInputComponent->BindAction("SlotAction_8", IE_Pressed, this, &ASPBaseCharacter::SlotAction8);
    PlayerInputComponent->BindAction("SlotAction_9", IE_Pressed, this, &ASPBaseCharacter::SlotAction9);
    PlayerInputComponent->BindAction("SlotAction_10", IE_Pressed, this, &ASPBaseCharacter::SlotAction10);
    PlayerInputComponent->BindAction("SlotAction_11", IE_Pressed, this, &ASPBaseCharacter::SlotAction11);
}

void ASPBaseCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void ASPBaseCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void ASPBaseCharacter::MoveForward(float Amount)
{
    if (Amount == 0.0f) return;
    auto ActorVectorYaw = GetControlRotation().Yaw;
    FRotator ActorVector = {0, ActorVectorYaw, 0};
    AddMovementInput(UKismetMathLibrary::GetForwardVector(ActorVector), Amount);
}

void ASPBaseCharacter::MoveRight(float Amount)
{
    if (Amount == 0.0f) return;
    auto ActorVectorYaw = GetControlRotation().Yaw;
    FRotator ActorVector = {0, ActorVectorYaw, 0};
    AddMovementInput(UKismetMathLibrary::GetRightVector(ActorVector), Amount);
}
void ASPBaseCharacter::SlotAction1()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[0];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction2()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[1];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction3()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[2];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction4()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[3];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction5()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[4];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction6()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[5];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction7()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[6];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction8()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[7];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction9()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[8];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction10()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[9];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
void ASPBaseCharacter::SlotAction11()
{
    if (SkillsComponent->GetCanCast() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can Cast True"));
        const auto Widget = SkillsComponent->GetArraySkillBottomBar()[10];
        if (Widget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Start Cast"));
            const auto Element = Widget->GetFBottomSlotActionInfo();
            SkillsComponent->StartAction(Element);
        }
    }
}
