// Fill out your copyright notice in the Description page of Project Settings.


#include "CircleSiegeGameMode.h"
#include "CameraOrbitPawn.h"

ACircleSiegeGameMode::ACircleSiegeGameMode()
{
	DefaultPawnClass = ACameraOrbitPawn::StaticClass();
}

void ACircleSiegeGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Current GameMode: %s"), *GetNameSafe(GetWorld()->GetAuthGameMode()));
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->SetInputMode(FInputModeGameAndUI());
	}
	
}
