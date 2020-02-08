// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS(Abstract, Blueprintable)
class SPELLCASTINGSYSTEM_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, Category = Gameplay)
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = Visual)
	class UParticleSystemComponent* OnOverlapParticle;

	UPROPERTY(VisibleAnywhere, Category = Movement)
	class UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ACharacter> CharacterClass;

	UPROPERTY(EditAnywhere)
	float Damage;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
