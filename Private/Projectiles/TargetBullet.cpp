// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetBullet.h"
#include "ElementalComponent.h"
#include "SpellCastingSystem.h"

void ATargetBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float Distance = FVector::Dist(DestLocation, this->GetActorLocation());

	UE_LOG(SpellCastingSystemLog, Display, TEXT("ATargetBullet::Tick DestLocation  is: %f"), *DestLocation.ToString());

	// I have set it just to make the Slow effect initializing bullet end in some case (a.k.a when it is moving towards through the cursor)
	if (Distance < 120.f && !bIsMarkedDead)
	{
		UE_LOG(SpellCastingSystemLog, Display, TEXT("ATargetBullet::Tick TargetBullet has reached location"));

		if (!bIsMarkedDead)
		{
			bIsMarkedDead = true;
			OnDestroyingBullet.Broadcast(this);
			OnDestroyingBullet.RemoveAll(this);
		}

		if (Destroy() == false)
		{
			UE_LOG(SpellCastingSystemLog, Error, TEXT("ATargetBullet::Tick -> Projectile is indestructable"));
		}
	}
}

void ATargetBullet::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
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

	if (!bIsMarkedDead)
	{
		bIsMarkedDead = true;
		OnDestroyingBullet.Broadcast(this);
		OnDestroyingBullet.RemoveAll(this);
	}

	Super::OnOverlap(OverlappedComp, Other, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
