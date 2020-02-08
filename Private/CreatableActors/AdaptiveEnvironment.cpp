// Fill out your copyright notice in the Description page of Project Settings.


#include "AdaptiveEnvironment.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "SpellCastingSystem.h"
#include "ElementalComponent.h"
#include "..\..\Public\CreatableActors\AdaptiveEnvironment.h"

// Sets default values
AAdaptiveEnvironment::AAdaptiveEnvironment()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AAdaptiveEnvironment::OnOverlap);

	OnOverlapParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	OnOverlapParticle->bAutoActivate = false;

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
}

void AAdaptiveEnvironment::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	{
		UElementalComponent* OtherElementalComponent = Other->FindComponentByClass<UElementalComponent>();

		if (OtherElementalComponent != nullptr)
		{
			if (OtherElementalComponent->ElementalEffect == EAbilityType::Fire)
			{
				ElementalComponent->OnOverlapWithFire(ElementalComponent);
			}

			if (OtherElementalComponent->ElementalEffect == EAbilityType::Frost)
			{
				ElementalComponent->OnOverlapWithFrost(ElementalComponent);
			}

			if (OtherElementalComponent->ElementalEffect == EAbilityType::Wind)
			{
				ElementalComponent->OnOverlapWithWind(ElementalComponent);
			}

			if (OtherElementalComponent->ElementalEffect == EAbilityType::Earth)
			{
				ElementalComponent->OnOverlapWithEarth(ElementalComponent);
			}

			if (OtherElementalComponent->ElementalEffect == EAbilityType::Lightning)
			{
				ElementalComponent->OnOverlapWithLightning(ElementalComponent);
			}

			if (OtherElementalComponent->ElementalEffect == EAbilityType::Toxic)
			{
				ElementalComponent->OnOverlapWithToxic(OtherElementalComponent);
			}

			// if TargetBullet->ElementalComponent->ElementalEffect == EabilityType::None -> doNothing()
		}
	}
}

// Called when the game starts or when spawned
void AAdaptiveEnvironment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAdaptiveEnvironment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

