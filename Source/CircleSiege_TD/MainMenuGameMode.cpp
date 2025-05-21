// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"

#include "Blueprint/UserWidget.h"

void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Current GameMode: %s"), *GetNameSafe(GetWorld()->GetAuthGameMode()));

	if (MainMenuWidget)
	{
		UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidget->GetClass());
		if (Menu)
		{
			Menu->AddToViewport();
			
			APlayerController* PC = GetWorld()->GetFirstPlayerController();
			if (PC)
			{
				PC->bShowMouseCursor = true;
				PC->SetInputMode(FInputModeUIOnly());
			}
		}
	}
}
