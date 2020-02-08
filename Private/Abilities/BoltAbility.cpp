// Fill out your copyright notice in the Description page of Project Settings.


#include "BoltAbility.h"
#include "Projectiles/Projectile.h"
#include "Engine/World.h"
#include "SpellCastingSystem.h"

void UBoltAbility::Activate(FVector Location, AActor* Source)
{
	Super::Activate(Location, Source);

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UBoltAbility::Activate IsValid(World) == false"));
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Source;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector Direction = Location - Source->GetActorLocation();
	Direction.Z = 0.0f;
	Direction.Normalize();

	FVector SpawnLocation = Source->GetActorLocation() + Direction * 100.0f;

	AActor* Projectile = World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, Direction.Rotation(), SpawnParameters);

	if (IsValid(Projectile) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("UBoltAbility::Activate IsValid(Projectile) == false"));
		return;
	}
}