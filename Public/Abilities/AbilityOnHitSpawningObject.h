// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityOnHitSpawningObject.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCASTINGSYSTEM_API UAbilityOnHitSpawningObject : public UAbility
{
	GENERATED_BODY()

public:
	virtual void Activate(FVector Location, AActor* Source) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ATargetBullet> BulletClass;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AActor> OnHitSpawningClass;

	UFUNCTION(BlueprintCallable)
	void OnBulletReachingDestination(AActor* Source);
};
