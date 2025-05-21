// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TimerManager.h"
#include "InputActionValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraOrbitPawn.generated.h"

class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;

UCLASS()
class CIRCLESIEGE_TD_API ACameraOrbitPawn : public APawn
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Camera")
	float RotationSpeed = 60.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> TurnCameraAction;


	ACameraOrbitPawn();
protected:	
	virtual void BeginPlay() override;	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void RotateCamera(const FInputActionValue& Value);	
};
