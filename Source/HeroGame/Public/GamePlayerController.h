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

	void ProcessRollInput(const FInputActionValue& Value);
	void ProcessJumpInput(const FInputActionValue& Value);
	void ProcessDashInput(const FInputActionValue& Value);
	void ProcessCameraRotateInput(const FInputActionValue& Value);
	void ProcessDebugMaterialSwitchInput(const FInputActionValue& Value);
	
	UPROPERTY()
	APlayerBallPawn* PossessedPawn;

protected:
	virtual void OnPossess(APawn* aPawn) override;

public:
	UPROPERTY(EditAnywhere, Category="Input")
	UInputMappingContext* HeroInputContext;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* RollAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;
    	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* DashAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* CameraRotateAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* DebugMaterialSwitchAction;
};
