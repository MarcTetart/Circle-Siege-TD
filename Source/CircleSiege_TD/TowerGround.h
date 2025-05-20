// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerGround.generated.h"

UCLASS()
class CIRCLESIEGE_TD_API ATowerGround : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	TObjectPtr<UStaticMeshComponent> GroundMesh;

	
	
public:	
	// Sets default values for this actor's properties
	ATowerGround();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Placement")
	bool IsValidPlacementAt(FVector Location) const;

};
