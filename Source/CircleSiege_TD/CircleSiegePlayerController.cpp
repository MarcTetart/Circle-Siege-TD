// Fill out your copyright notice in the Description page of Project Settings.


#include "CircleSiegePlayerController.h"
#include "EnhancedInputSubsystems.h"


void ACircleSiegePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}
