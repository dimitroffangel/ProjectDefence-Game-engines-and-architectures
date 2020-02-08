// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityOnHitSpawningObject.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "TargetBullet.h"
#include "Engine/World.h"

void UAbilityOnHitSpawningObject::Activate(FVector Location, AActor* Source)
{
	Super::Activate(Location, Source);

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("AbilityOnHitSpawningObject::Activate IsValid(World) == false"));
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Source;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLocation = Source->GetActorLocation() + Source->GetActorForwardVector() * 100.0f;

	ATargetBullet* Projectile = World->SpawnActor<ATargetBullet>(BulletClass, SpawnLocation, Source->GetActorRotation(), SpawnParameters);

	if (IsValid(Projectile) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("AbilityOnHitSpawningObject::Activate IsValid(Projectile) == false"));
		return;
	}

	ACharacter* Character = Cast<ACharacter>(Source);

	if (IsValid(Character) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("AbilityOnHitSpawningObject::Activate IsValid(Character) == false"));
		return;
	}

	//UDecalComponent* CursorToWorld = Character->GetCursorToWorld();
	const float SetForwardVectorMagnituteTo = 500.0f;
	FVector CharacterForwardVector = Character->GetActorForwardVector();
	CharacterForwardVector.Normalize();
	CharacterForwardVector *= SetForwardVectorMagnituteTo;
	FVector CharacterLocation = Character->GetActorLocation();

	if (IsValid(Character) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("AbilityOnHitSpawningObject::Activate IsValid(CursorToWorld) == false"));
		return;
	}

	Projectile->SetDestLocation(CharacterForwardVector + CharacterLocation);

	Projectile->OnDestroyingBullet.AddUObject(this, &UAbilityOnHitSpawningObject::OnBulletReachingDestination);
}

void UAbilityOnHitSpawningObject::OnBulletReachingDestination(AActor* Source)
{
	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(SpellCastingSystemLog, Error, TEXT("AbilityOnHitSpawningObject::OnBulletReachingDestination IsValid(World) == false"));
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Source;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	FVector SpawnLocation = Source->GetActorLocation();

	AActor* OnHitActor = World->SpawnActor<AActor>(OnHitSpawningClass, SpawnLocation, Source->GetActorRotation(), SpawnParameters);

	if (IsValid(OnHitActor) == false)
	{
		UE_LOG(SpellCastingSystemLog, Warning, TEXT("AbilityOnHitSpawningObject::OnBulletReachingDestination IsValid(Projectile) == false"));
		return;
	}
}