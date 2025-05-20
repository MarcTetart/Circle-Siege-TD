// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerGround.h"

// Sets default values
ATowerGround::ATowerGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerGround::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATowerGround::IsValidPlacementAt(FVector Location) const
{
	// 1. Vérifie que le point appartient bien à ce sol (simplement ici par distance au centre)
	FVector GroundCenter = GetActorLocation();
	float Radius = 500.f; // Par exemple, ton cercle de pose
	float DistanceToCenter = FVector::Dist2D(GroundCenter, Location);

	if (DistanceToCenter > Radius)
	{
		UE_LOG(LogTemp, Warning, TEXT("Position hors du cercle de placement autorisé."));
		return false;
	}

	// 2. Vérifie les collisions autour de ce point (éviter le chevauchement de tours)
	FCollisionShape Sphere = FCollisionShape::MakeSphere(100.f); // Rayon minimal autour de la tour
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // Ignore ce sol

	bool bHit = GetWorld()->OverlapAnyTestByChannel(
		Location,
		FQuat::Identity,
		ECC_WorldDynamic,
		Sphere,
		Params
	);

	if (bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Zone déjà occupée par un autre objet."));
		return false;
	}

	// 3. Tout est OK
	return true;
}

