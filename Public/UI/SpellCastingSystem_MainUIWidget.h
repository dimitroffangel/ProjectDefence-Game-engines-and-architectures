// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpellCastingSystem_MainUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCASTINGSYSTEM_API USpellCastingSystem_MainUIWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	USpellCastingSystem_MainUIWidget(const FObjectInitializer& ObjectInitializer);

	// Optionally override the Blueprint "Event Construct" event
	virtual void NativeConstruct() override;

	// Optionally override the tick event
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	

public:
	UFUNCTION(BlueprintCallable)
	void AbilityButtonClicked(class ACharacter* Character, uint8 AbilityIndex);

	UFUNCTION(BlueprintCallable)
	void AbilityProgressBar(float DeltaTime, UPARAM(ref) float& CooldownTimeAbility, float InitialCooldownTimeAbility, UPARAM(ref) float& AbilityCooldownPercent);

	UFUNCTION(BlueprintCallable)
	void ChangingAbility(uint8 AbilityIndex);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class APlayerController> CastToController;

	// first ability cooldown variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownTimeFirstAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialCooldownTimeFirstAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FirstAbilityCooldownPercent;

	// second ability cooldown variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownTimeSecondAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialCooldownTimeSecondAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SecondAbilityCooldownPercent;

	// third ability cooldown variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownTimeThirdAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialCooldownTimeThirdAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ThirdAbilityCooldownPercent;

	// fourth abiltiy cooldown variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownTimeFourthAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialCooldownTimeFourthAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FourthAbilityCooldownPercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsChangingFirstAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsChangingSecondAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsChangingThirdAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsChangingFourthAbility;

};
