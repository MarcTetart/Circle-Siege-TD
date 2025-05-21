// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraOrbitPawn.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


ACameraOrbitPawn::ACameraOrbitPawn()
{ 	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	RootComponent = SpringArm;
	SpringArm->TargetArmLength = 2000.0f;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bDoCollisionTest = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
}


void ACameraOrbitPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACameraOrbitPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (TurnCameraAction)
		{
			Input->BindAction(TurnCameraAction, ETriggerEvent::Triggered, this, &ACameraOrbitPawn::RotateCamera);
		}
	}
}

void ACameraOrbitPawn::RotateCamera(const FInputActionValue& Value)
{
	const float Axis = Value.Get<float>();	
	if (FMath::Abs(Axis) > KINDA_SMALL_NUMBER)
	{
		FRotator NewRot = GetActorRotation();
		NewRot.Yaw += Axis * RotationSpeed * GetWorld()->GetDeltaSeconds();
		SetActorRotation(NewRot);
	}
}



