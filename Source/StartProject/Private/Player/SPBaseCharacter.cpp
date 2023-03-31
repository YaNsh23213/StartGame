// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/SPBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/Components/SPSkillsComponent.h"
#include "Player/Components/SPBSComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Component/SPHealthComponent.h"
#include "Enemy/SPHealthAIAComponent.h"
#include "Enemy/SPEnemyCharacter.h"
#include "Enemy/SPHealthBarWidget.h"
#include "Skills/SPBottomBarSkillsWidget.h"
#include "Player/HealBoost/SPHealBoostWidget.h"
#include "Components/SphereComponent.h"

ASPBaseCharacter::ASPBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArmComponent"));
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->bUsePawnControlRotation = true;
    SkillsComponent = CreateDefaultSubobject<USPSkillsComponent>("SkillsComponent");
    BSComponent = CreateDefaultSubobject<USPBSComponent>("BSComponent");
    HealthComponent = CreateDefaultSubobject<USPHealthComponent>("HealthComponent");
    SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    SphereComponent->SetupAttachment(RootComponent);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp3P"));
    CameraComponent->SetupAttachment(SpringArmComponent);

    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ASPBaseCharacter::BeginOverlapNPC);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ASPBaseCharacter::EndOverlapNPC);
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
    WidgetPauseInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
    WidgetEnemyInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetEnemy);
    BottomBarInstance = CreateWidget<UUserWidget>(GetWorld(), BottomBar);
    HealBoostInstance = CreateWidget<UUserWidget>(GetWorld(), HealBoost);
    RequestInteractInstance = CreateWidget<UUserWidget>(GetWorld(), RequestInteract);
    BottomBarInstance->AddToViewport();
    HealBoostInstance->AddToViewport();
    if (HealthComponent)
    {
        // HealthComponent->IsDead.
    }
}

void ASPBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (BSStatus == true)
    {
        if (IsEnemyWidgwetAdded == false)
        {
            WidgetEnemyInstance->AddToViewport();
            IsEnemyWidgwetAdded = true;
            Cast<USPHealthBarWidget>(WidgetEnemyInstance)->InitEmenyHP();
        }
    }
}
void ASPBaseCharacter::BeginOverlapNPC(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Display, TEXT("Start Overlap"));
    CanInteract = true;
    RequestInteractInstance->AddToViewport();
}
void ASPBaseCharacter::EndOverlapNPC(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Display, TEXT("End Overlap"));
    CanInteract = false;
    Interact();
}
void ASPBaseCharacter::ClearWidgetEnemy()
{
    WidgetEnemyInstance->RemoveFromViewport();
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

    PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &ASPBaseCharacter::Pause);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASPBaseCharacter::Jump);

    PlayerInputComponent->BindAction("Heal", IE_Pressed, this, &ASPBaseCharacter::UseHealPotion);
    PlayerInputComponent->BindAction("Boost", IE_Pressed, this, &ASPBaseCharacter::UseBoostPotion);

    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ASPBaseCharacter::Interact);
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

void ASPBaseCharacter::Pause()
{
    auto PlayerController = Cast<APlayerController>(GetController());
    UGameplayStatics::SetGamePaused(GetWorld(), true);
    FInputModeUIOnly UI;
    PlayerController->SetInputMode(UI);
    PlayerController->bShowMouseCursor = true;
    WidgetPauseInstance->AddToViewport();
}
void ASPBaseCharacter::UseHealPotion()
{
    auto Widget = Cast<USPHealBoostWidget>(HealBoostInstance);
    if (Widget)
    {
        auto AmountHeal = Widget->GetAmountHeal();
        if (AmountHeal > 0)
        {
            HealthComponent->HealUp(30.0f);
            AmountHeal = AmountHeal - 1;
            Widget->SetAmountHeal(AmountHeal);
            Widget->HealUpdate(FText::FromString(FString::FromInt(AmountHeal)));
        }
    }
}
void ASPBaseCharacter::UseBoostPotion()
{
    auto Widget = Cast<USPHealBoostWidget>(HealBoostInstance);
    if (Widget)
    {
        auto AmountBoost = Widget->GetAmountBoost();
        if (AmountBoost > 0)
        {
            if (HealthComponent->GetArmorModifier() <= 0.0f)
            {
                HealthComponent->SetArmorModifier(10.0f);
                AmountBoost = AmountBoost - 1;
                Widget->SetAmountBoost(AmountBoost);
                Widget->BoostUdate(FText::FromString(FString::FromInt(AmountBoost)));
                GetWorld()->GetTimerManager().SetTimer(BaseHandle, this, &ASPBaseCharacter::AddBostTime, 10.0f, false);
            }
        }
    }
}
void ASPBaseCharacter::AddBostTime()
{
    HealthComponent->SetArmorModifier(0.0f);
    GetWorld()->GetTimerManager().ClearTimer(BaseHandle);
}
void ASPBaseCharacter::Interact()
{
    if (OpenInteract == true)
    {
        UE_LOG(LogTemp, Display, TEXT("Close Alchemist Shop"));
        OpenInteract = false;
        return;
    }
    if (CanInteract == true && OpenInteract == false)
    {
        RequestInteractInstance->RemoveFromViewport();
        UE_LOG(LogTemp, Display, TEXT("Open Alchemist Shop"));
        OpenInteract = true;
        return;
    }
    if (CanInteract == false)
    {
        UE_LOG(LogTemp, Display, TEXT("Not In Radius"));
        return;
    }
}
