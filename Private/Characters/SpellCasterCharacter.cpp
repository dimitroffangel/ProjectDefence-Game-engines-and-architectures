// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCasterCharacter.h"
#include "SpellCastingSystem.h"

// Sets default values
ASpellCasterCharacter::ASpellCasterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	OnTakeAnyDamage.AddDynamic(this, &ASpellCasterCharacter::TakeAnyDamage);
}

// Called when the game starts or when spawned
void ASpellCasterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaximumHealth;
}

// Called every frame
void ASpellCasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpellCasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASpellCasterCharacter::TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigateBy, AActor* DamageCauser)
{
	UE_LOG(SpellCastingSystemLog, Display, TEXT("ASpellCasterCharacter::TakeAnyDamage current health = %f"), (Health - Damage));
	Health -= Damage;

	if (Health <= 0.0f)
	{
		//Death();
	}
}

