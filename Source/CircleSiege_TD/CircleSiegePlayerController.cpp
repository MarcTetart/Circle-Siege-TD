// Fill out your copyright notice in the Description page of Project Settings.


#include "CircleSiegePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerBuilder.h"
#include "TowerGround.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"


void ACircleSiegePlayerController::ActivateGameplayMapping(){
	
	UE_LOG(LogTemp, Display, TEXT("Activating Gameplay Mapping"));
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{		
		if (GameplayMappingContext)
		{
			Subsystem->AddMappingContext(GameplayMappingContext, 1); // Priorité 1 > 0
		}
	}
}

void ACircleSiegePlayerController::ActivateUIMapping()
{
	UE_LOG(LogTemp, Display, TEXT("Activating UIMapping"));
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (UIMappingContext)
		{
			Subsystem->RemoveMappingContext(UIMappingContext);
		}		
	}
}

void ACircleSiegePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (GameplayMappingContext)
		{
			Subsystem->AddMappingContext(GameplayMappingContext, 0);
		}
	}
}

void ACircleSiegePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (PauseMenuAction)
		{
			Input->BindAction(PauseMenuAction, ETriggerEvent::Started, this, &ACircleSiegePlayerController::TogglePauseMenu);
			Input->BindAction(ShootLineTraceAction, ETriggerEvent::Started, this, &ACircleSiegePlayerController::OnMoveBuilderInput);
		}
	}
}

void ACircleSiegePlayerController::TogglePauseMenu()
{
	UE_LOG(LogTemp, Display, TEXT("press A"));
	if (bIsPauseMenuVisible)
	{
		// Close Pause Menu
		UE_LOG(LogTemp, Display, TEXT("Close Pause Menu"));
		if (PauseMenuInstance)
		{
			PauseMenuInstance->RemoveFromParent();
			PauseMenuInstance = nullptr;
		}
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		ActivateGameplayMapping();
		bIsPauseMenuVisible = false;
	}
	else
	{
		// Open Pause Menu
		UE_LOG(LogTemp, Error, TEXT("Open Pause Menu"));
		if (PauseMenuClass)
		{
			PauseMenuInstance = CreateWidget<UUserWidget>(this, PauseMenuClass);
			if (PauseMenuInstance)
			{
				PauseMenuInstance->AddToViewport();
			}
		}
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		ActivateUIMapping();
		bIsPauseMenuVisible = true;
	}
}

void ACircleSiegePlayerController::OnMoveBuilderInput()
{
	if (bIsPauseMenuVisible)return;
	FHitResult Hit;
	if (GetHitResultUnderCursor(ECC_Visibility, false, Hit))
	{
		FVector Start = PlayerCameraManager->GetCameraLocation();
		FVector End = Hit.ImpactPoint;

		/*// Ligne verte du rayon jusqu’à la cible
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 2.0f, 0, 2.0f);*/

		// Petite sphère sur la cible
		DrawDebugSphere(GetWorld(), End, 25.0f, 12, FColor::Red, false, 2.0f);

		if (Hit.bBlockingHit && Hit.GetActor()->IsA(ATowerGround::StaticClass()))
		{
			if (APlayerBuilder* Builder = Cast<APlayerBuilder>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerBuilder::StaticClass())))
			{
				Builder->MoveToLocation(Hit.ImpactPoint);
				UE_LOG(LogTemp, Display, TEXT("Move Builder to %s"), *Hit.ImpactPoint.ToString());
			}
		}
	}
}
