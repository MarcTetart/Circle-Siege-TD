// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CircleSiegeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CIRCLESIEGE_TD_API ACircleSiegeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACircleSiegeGameMode();

	virtual void BeginPlay() override;
};
