#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CircleSiegePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CIRCLESIEGE_TD_API ACircleSiegePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
};
