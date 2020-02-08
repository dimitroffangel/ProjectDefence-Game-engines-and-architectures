// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"
#include "SpellCastingSystem.h"
#include "AbilityStruct.h"
#include "MageComponent.h"

UAbility::UAbility()
{
	FAbilityStruct* AbilityStruct = AbilityStatsRow.GetRow<FAbilityStruct>(TEXT(""));

	if (AbilityStruct == nullptr)
	{
		UE_LOG(SpellCastingSystemLog, Display, TEXT("UAbility::UAbility AbilityStruct is nullptr..."));
		return;
	}

	CooldownTime = AbilityStruct->CooldownTime;
	AbilityManaCost = AbilityStruct->AbilityManaCost;
	AbilityType = AbilityStruct->AbilityType;
}

void UAbility::Activate(FVector Location, AActor* Source)
{
	if (bIsOffCooldown == false)
	{
		UE_LOG(SpellCastingSystemLog, Display, TEXT("UAbility::Activate Ability is on cooldown..."));
		return;
	}

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UAbility::Activate IsValid(World) == false"));
		return;
	}

	if (IsValid(Source) == false )
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UAbility::Activate IsValid(Source) == false"));
		return;
	}
	
	UMageComponent* MageComponent = Source->FindComponentByClass<UMageComponent>();

	if (MageComponent == nullptr)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UAbility::Activate MageComponnent is nullptr == false"));
		return;
	}

	if (MageComponent->Mana < AbilityManaCost)
	{
		UE_LOG(SpellCastingSystemLog, Display, TEXT("UAbility::Activate Source Actor has not enough mana..."));
		return;
	}

	// take mana from the Actor
	MageComponent->Mana -= AbilityManaCost;

	if (MageComponent->Mana < 0.f)
	{
		MageComponent->Mana = 0.f;
	}

	TimerManager = &World->GetTimerManager();
	TimerManager->SetTimer(CooldownTimerHandle, this, &UAbility::OnCooldownTimerExpired, CooldownTimeDilation, true, CooldownTime);
	bIsOffCooldown = false;

	if (IsValid(Source) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UAbility::Activate IsValid(Source) == false"));
		return;
	}

	OnActivateBlueprint(Source);
}

void UAbility::OnCooldownTimerExpired()
{
	bIsOffCooldown = true;
}

void UAbility::BeginDestroy()
{
	if (TimerManager)
	{
		TimerManager->ClearTimer(CooldownTimerHandle);
		TimerManager = nullptr;
	}
	Super::BeginDestroy();
}