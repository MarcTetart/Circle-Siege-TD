// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBuilder.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerBuilder::APlayerBuilder()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsMoving)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Direction = (MoveTarget - CurrentLocation);
		float Distance = Direction.Size2D();

		if (Distance < MoveAcceptRadius)
		{
			bIsMoving = false;
			GetCharacterMovement()->StopMovementImmediately();
			return;
		}

		Direction.Z = 0.f;
		Direction.Normalize();

		AddMovementInput(Direction, 1.0f);
	}

}

// Called to bind functionality to input
void APlayerBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerBuilder::MoveToLocation(const FVector& TargetLocation)
{
	MoveTarget = TargetLocation;
	bIsMoving = true;
}


