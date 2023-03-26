// Fill out your copyright notice in the Description page of Project Settings.

#include "Skills/Spells/STCastSpellActor.h"
#include "Player/SPBaseCharacter.h"
#include "Player/Components/SPSkillsComponent.h"
#include "Player/AnimNotify/SPSpawnProjectileAnimNotify.h"
#include "Player/AnimNotify/SPEndAnimatoinAnimNotify.h"

void ASTCastSpellActor::StartAction(AActor* OwnerActor)
{
    Super::StartAction(OwnerActor);
    if (!OwnerActor || !AnimMontage) return;
    CurrentOwner = OwnerActor;
    UE_LOG(LogTemp, Warning, TEXT("Cast activated"));
    UE_LOG(LogTemp, Warning, TEXT("Owner Name %s"), *OwnerActor->GetName());
    const auto Player = Cast<ASPBaseCharacter>(CurrentOwner);
    if (!Player) return;
    const auto SkillsComponent = Player->FindComponentByClass<USPSkillsComponent>();
    if (SkillsComponent)
    {
        SkillsComponent->SetCanCast(false);
        SkillsComponent->SetCastInProgress(true);
        LevelSpel = SkillsComponent->GetLevelCast();
    }
    InitAnimations();
    Player->PlayAnimMontage(AnimMontage);
}

void ASTCastSpellActor::InitAnimations()
{
    const auto Player = Cast<ASPBaseCharacter>(CurrentOwner);
    if (!Player || !AnimMontage) return;
    const auto NotifyEvents = AnimMontage->Notifies;
    for (auto NotifyEvent : NotifyEvents)
    {
        auto SpawnProjectile = Cast<USPSpawnProjectileAnimNotify>(NotifyEvent.Notify);
        auto EndAnimation = Cast<USPEndAnimatoinAnimNotify>(NotifyEvent.Notify);
        if (SpawnProjectile)
        {
            SpawnProjectile->OnSpawnProjectile.AddUObject(this, &ASTCastSpellActor::SpawnProjectile);
        }
        if (EndAnimation)
        {
            EndAnimation->OnEndAnimation.AddUObject(this, &ASTCastSpellActor::EndAnimation);
        }
    }
}

void ASTCastSpellActor::SpawnProjectile()
{
    const auto Player = Cast<ASPBaseCharacter>(CurrentOwner);
    if (!Player) return;
    const auto CurrentForwardVector = Player->GetActorForwardVector();
    const auto Location = Player->GetMesh()->GetSocketLocation("WeaponSocket") + CurrentForwardVector * 100;
    const auto Rotation = Player->GetActorRotation();
    FActorSpawnParameters SpawnParams;
    if (LevelSpel == 1)
    {
        UE_LOG(LogTemp, Display, TEXT("Use %i Level Cast"), LevelSpel);
        GetWorld()->SpawnActor<AActor>(Spell_1, Location, Rotation, SpawnParams);
    }
    if (LevelSpel == 2)
    {
        UE_LOG(LogTemp, Display, TEXT("Use %i Level Cast"), LevelSpel);
        GetWorld()->SpawnActor<AActor>(Spell_2, Location, Rotation, SpawnParams);
    }
    if (LevelSpel == 3)
    {
        UE_LOG(LogTemp, Display, TEXT("Use %i Level Cast"), LevelSpel);
        GetWorld()->SpawnActor<AActor>(Spell_3, Location, Rotation, SpawnParams);
    }
}

void ASTCastSpellActor::EndAnimation()
{
    const auto Player = Cast<ASPBaseCharacter>(CurrentOwner);
    const auto Component = Player->FindComponentByClass<USPSkillsComponent>();
    if (Component)
    {
        Component->SetCanCast(true);
        Component->SetCastInProgress(false);
    }
    this->Destroy();
}
