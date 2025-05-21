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
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> GameplayMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> UIMappingContext;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> PauseMenuAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> ShootLineTraceAction;
	
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> PauseMenuClass;

	
	UPROPERTY(EditAnywhere, Category = "UI")
	TObjectPtr<UUserWidget> PauseMenuInstance = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "UI")
	bool bIsPauseMenuVisible = false;


	
	void ActivateGameplayMapping();
	void ActivateUIMapping();
public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable)
	void TogglePauseMenu();

	UFUNCTION()
	void OnMoveBuilderInput();

	
};
