// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityStruct.h"
#include "ElementalComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPELLCASTINGSYSTEM_API UElementalComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UElementalComponent();

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithFire(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithFireActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithFrost(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithFrostActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithWind(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithWindActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithEarth(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithEarthActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithLightning(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithLightningActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithKinetic(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithKineticActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapWithToxic(UElementalComponent* OverlappingElementalComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlapWithToxicActivateBlueprint(UElementalComponent* OverlappingElementalComponent);

	UPROPERTY(EditAnywhere)
	EAbilityType ElementalEffect;


	UPROPERTY(EditAnywhere)
	EAbilityType AffectedBy = EAbilityType::None;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
