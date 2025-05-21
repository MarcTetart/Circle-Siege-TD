// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBuilder.generated.h"

class UInputAction;

UCLASS()
class CIRCLESIEGE_TD_API APlayerBuilder : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Builder")
	float MoveAcceptRadius = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Builder")
	FVector MoveTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Builder")
	bool bIsMoving = false;

public:
	// Sets default values for this character's properties
	APlayerBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
	void MoveToLocation(const FVector& TargetLocation);
};
