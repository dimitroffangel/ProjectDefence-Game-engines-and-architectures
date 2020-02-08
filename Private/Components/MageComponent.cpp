// Fill out your copyright notice in the Description page of Project Settings.


#include "MageComponent.h"
#include "Ability.h"
#include "SpellCastingSystem.h"

// Sets default values for this component's properties
UMageComponent::UMageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMageComponent::BeginPlay()
{
	Super::BeginPlay();

	SpellsEquipped.Reserve(MaxLengthOfSpellsEquipped);

	// ...
	
	for (const TSubclassOf<UAbility>& AbilityAcquired : SpellsAcquired)
	{
		SpellsEquipped.Push(NewObject<UAbility>(this, AbilityAcquired));
	}
}


// Called every frame
void UMageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMageComponent::CastEquippedAbility(const uint8 Index, FVector Location, AActor* Source)
{
	if (Index >= SpellsEquipped.Num())
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UMageComponent::CastEquipredAbility Index >= SpellsEquipped.Num()"));
		return;
	}

	UAbility* Ability = SpellsEquipped[Index];
	if (IsValid(Ability))
	{
		Ability->Activate(Location, Source);
		return;
	}

	return;
}

void UMageComponent::SwapEquipedAbilityWithAcquiredAbility(uint8 EquippedAbilityIndex, uint8 AcquiredAbilityIndex)
{
	if (EquippedAbilityIndex >= SpellsEquipped.Num())
	{
		if (SpellsEquipped.Num() < MaxLengthOfSpellsEquipped && EquippedAbilityIndex == SpellsEquipped.Num())
		{
			if (AcquiredAbilityIndex >= SpellsAcquired.Num())
			{
				UE_LOG(SpellCastingSystemLog, Error, TEXT("UMageComponent::SwapEquipedAbilityWithAcquiredAbility AcquiredAbilityIndex >= SpellsAcquired.Num()"));
					return;
			}

			SpellsEquipped.Push(NewObject<UAbility>(this, SpellsAcquired[AcquiredAbilityIndex]));
			return;
		}

		UE_LOG(SpellCastingSystemLog, Error, TEXT("UMageComponent::SwapEquipedAbilityWithAcquiredAbility EquippedAbilityIndex >= SpellsEquipped.Num()"));
		return;
	}

	if (AcquiredAbilityIndex >= SpellsAcquired.Num())
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UMageComponent::SwapEquipedAbilityWithAcquiredAbility AcquiredAbilityIndex >= SpellsAcquired.Num()"));
		return;
	}

	SpellsEquipped[EquippedAbilityIndex] = NewObject<UAbility>(this, SpellsAcquired[AcquiredAbilityIndex]);
}

