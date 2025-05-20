// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraOrbitPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACameraOrbitPawn::ACameraOrbitPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create SpingArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	RootComponent = SpringArm;
	SpringArm->TargetArmLength = 2000.0f;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bDoCollisionTest = false;

	//Create Camera
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ACameraOrbitPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraOrbitPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraOrbitPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

