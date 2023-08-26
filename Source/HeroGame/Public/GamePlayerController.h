// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystemInterface.h"
#include "PlayerBallPawn.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HEROGAME_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void SetupInputComponent() override;

	void HandleRollInput(const FInputActionValue& Value);

	UPROPERTY()
	APlayerBallPawn* PossessedPawn;

protected:
	virtual void OnPossess(APawn* aPawn) override;

public:
	UPROPERTY(EditAnywhere, Category="Input")
	UInputMappingContext* HeroInputContext;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* RollAction;
};
