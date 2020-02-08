// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityStruct.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SPELLCASTINGSYSTEM_API UAbility : public UObject
{
	GENERATED_BODY()

public:
	UAbility();

public:

	FORCEINLINE bool IsOffCooldown() const { return bIsOffCooldown; }

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CooldownTime = 5.f;
	
	UPROPERTY(EditAnywhere)
	float CooldownTimeDilation = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AbilityManaCost = 20.f;

	UPROPERTY(EditAnywhere)
	EAbilityType AbilityType;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle AbilityStatsRow;

	UFUNCTION(BlueprintCallable)
	virtual void Activate(FVector Location, AActor* Owner);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivateBlueprint(AActor* Owner);

	virtual void BeginDestroy() override;

private:
	bool bIsOffCooldown = true;
	FTimerManager* TimerManager = nullptr;
	FTimerHandle CooldownTimerHandle;
	void OnCooldownTimerExpired();


};