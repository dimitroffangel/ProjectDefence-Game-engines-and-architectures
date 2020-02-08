// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Engine/DataTable.h"
#include "AbilityStruct.generated.h"

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	Fire UMETA(DisplayName = "Fire"),
	Frost UMETA(DisplayName = "Frost"),
	Wind UMETA(DisplayName = "Wind"),
	Earth UMETA(DisplayName = "Earth"),
	Lightning UMETA(DisplayName = "Lightning"),
	Kinetic UMETA(DisplayName = "Kinetic"),
	Toxic UMETA(DisplayName = "Toxic"),
	None UMETA(DisplayName = "None")
};

USTRUCT(BlueprintType)
struct FAbilityStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float CooldownTime = 1.f;

	UPROPERTY(EditAnywhere)
	EAbilityType AbilityType;

	UPROPERTY(EditAnywhere)
	float AbilityManaCost = 20.f;
};
