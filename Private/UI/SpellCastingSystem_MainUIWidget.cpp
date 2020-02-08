// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCastingSystem_MainUIWidget.h"
#include "MageComponent.h"
#include "Ability.h"
#include "GameFramework/Character.h"
#include "SpellCastingSystem.h"


USpellCastingSystem_MainUIWidget::USpellCastingSystem_MainUIWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void USpellCastingSystem_MainUIWidget::NativeConstruct()
{
	// Do some custom setup

	// Call the Blueprint "Event Construct" node
	Super::NativeConstruct();
}


void USpellCastingSystem_MainUIWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	// Make sure to call the base class's NativeTick function
	Super::NativeTick(MyGeometry, InDeltaTime);

	// Do your custom tick stuff here
}

void USpellCastingSystem_MainUIWidget::AbilityButtonClicked(ACharacter* Character, uint8 AbilityIndex)
{
	if (Character == nullptr)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("USpellCastingSystem_MainWidget::AbilityButtonClicked Character is nullptr"));
		return;
	}

	UMageComponent* MageComponent = Character->FindComponentByClass<UMageComponent>();

	if (MageComponent == nullptr)
	{
		UE_LOG(SpellCastingSystemLog, Display, TEXT("USpellCastingSystem_MainWidget::AbilityButtonClicked Character does not have MageComponent"));
		return;
	}

	if (AbilityIndex >= MageComponent->SpellsEquipped.Num())
	{
		UE_LOG(SpellCastingSystemLog, Display, TEXT("USpellCastingSystem_MainWidget::AbilityButtonClicked Index >= SpellsEquipped.Num()"));
		return;
	}

	if (MageComponent->SpellsEquipped[AbilityIndex]->IsOffCooldown())
	{
		return;
	}

	if (AbilityIndex == 0)
	{
		InitialCooldownTimeFirstAbility = CooldownTimeFirstAbility = MageComponent->SpellsEquipped[AbilityIndex]->CooldownTime;
	}

	else if (AbilityIndex == 1)
	{
		InitialCooldownTimeSecondAbility = CooldownTimeSecondAbility = MageComponent->SpellsEquipped[AbilityIndex]->CooldownTime;
	}

	else if (AbilityIndex == 2)
	{
		InitialCooldownTimeThirdAbility = CooldownTimeThirdAbility = MageComponent->SpellsEquipped[AbilityIndex]->CooldownTime;
	}
	
	else if (AbilityIndex == 3)
	{
		InitialCooldownTimeFourthAbility = CooldownTimeFourthAbility = MageComponent->SpellsEquipped[AbilityIndex]->CooldownTime;
	}
}

void USpellCastingSystem_MainUIWidget::AbilityProgressBar(float DeltaTime, UPARAM(ref) float& CooldownTimeAbility, 
	float InitialCooldownTimeAbility, UPARAM(ref)float& AbilityCooldownPercent)
{
	if (CooldownTimeAbility <= 0.0)
	{
			return;
	}

	CooldownTimeAbility -= DeltaTime;

	AbilityCooldownPercent = CooldownTimeAbility / InitialCooldownTimeAbility;
}

void USpellCastingSystem_MainUIWidget::ChangingAbility(uint8 AbilityIndex)
{
	if (AbilityIndex == 0)
	{
		if (bIsChangingFirstAbility)
		{
			bIsChangingFirstAbility = false;
		}

		else
		{
			bIsChangingFirstAbility = true;
			bIsChangingSecondAbility = bIsChangingThirdAbility = bIsChangingFourthAbility = false;
		}

		return;
	}

	if (AbilityIndex == 1)
	{
		if (bIsChangingSecondAbility)
		{
			bIsChangingSecondAbility = false;
		}

		else
		{
			bIsChangingSecondAbility = true;
			bIsChangingFirstAbility = bIsChangingThirdAbility = bIsChangingFourthAbility = false;
		}

		return;
	}

	if (AbilityIndex == 2)
	{
		if (bIsChangingThirdAbility)
		{
			bIsChangingThirdAbility = false;
		}

		else
		{
			bIsChangingThirdAbility = true;
			bIsChangingFirstAbility = bIsChangingSecondAbility = bIsChangingFourthAbility = false;
		}
	}

	if (AbilityIndex == 3)
	{
		if (bIsChangingFourthAbility)
		{
			bIsChangingFourthAbility = false;
		}

		else
		{
			bIsChangingFourthAbility = true;
			bIsChangingFirstAbility = bIsChangingSecondAbility = bIsChangingThirdAbility = false;
		}
	}
}
