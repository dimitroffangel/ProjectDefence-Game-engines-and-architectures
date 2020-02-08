// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "SpellCastingSystem.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigateBy, AActor* DamageCauser)
{
	UE_LOG(SpellCastingSystemLog, Display, TEXT("ASpellCasterCharacter::TakeAnyDamage current health = %f"), (Health - Damage));
	Health -= Damage;

	if (Health <= 0.0f)
	{
		//Death();
	}
}

