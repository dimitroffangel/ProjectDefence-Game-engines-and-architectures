// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "BoltAbility.generated.h"

UCLASS()
class SPELLCASTINGSYSTEM_API UBoltAbility : public UAbility
{
	GENERATED_BODY()

public:
	virtual void Activate(FVector Location, AActor* Source) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;
};
