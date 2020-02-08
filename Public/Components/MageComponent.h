// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MageComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPELLCASTINGSYSTEM_API UMageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	TArray<class UAbility*> SpellsEquipped;

	UFUNCTION(BlueprintCallable)
	void CastEquippedAbility(const uint8 Index, FVector Location, AActor* Source);

	UFUNCTION(BlueprintCallable)
	void SwapEquipedAbilityWithAcquiredAbility(const uint8 EquippedAbilityIndex, const uint8 AcquiredAbilityIndex);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Mana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<class UAbility>> SpellsAcquired;
	
private:
	const uint8 MaxLengthOfSpellsEquipped = 4;
};
