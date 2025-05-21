// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CIRCLESIEGE_TD_API AMainMenuGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CircleSiege")
	TObjectPtr<UUserWidget> MainMenuWidget;

	virtual void BeginPlay() override;
};
