// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerController.h"
#include "LogUtil.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"

void AGamePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
	PossessedPawn = Cast<APlayerBallPawn>(aPawn);
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	
	if(UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subsystem->AddMappingContext(HeroInputContext,0);
	}

	enhancedInput->BindAction(RollAction, ETriggerEvent::Triggered, this, &AGamePlayerController::ProcessRollInput);
	enhancedInput->BindAction(DashAction, ETriggerEvent::Triggered, this, &AGamePlayerController::ProcessDashInput);
	enhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AGamePlayerController::ProcessJumpInput);
	enhancedInput->BindAction(CameraRotateAction, ETriggerEvent::Triggered, this, &AGamePlayerController::ProcessCameraRotateInput);
	enhancedInput->BindAction(DebugMaterialSwitchAction, ETriggerEvent::Triggered, this, &AGamePlayerController::ProcessDebugMaterialSwitchInput);
}

void AGamePlayerController::ProcessRollInput(const FInputActionValue& Value)
{
	const FVector2d rollVector = Value.Get<FVector2d>();

	PossessedPawn->Roll(rollVector);
}

void AGamePlayerController::ProcessJumpInput(const FInputActionValue& Value)
{
	PossessedPawn->Jump();
}

void AGamePlayerController::ProcessDashInput(const FInputActionValue& Value)
{
	PossessedPawn->Dash(PossessedPawn->MovementDirection);
}

void AGamePlayerController::ProcessCameraRotateInput(const FInputActionValue& Value)
{
	const float axis = Value.Get<float>();
	PossessedPawn->RotateCamera(axis);
}

void AGamePlayerController::ProcessDebugMaterialSwitchInput(const FInputActionValue& Value)
{
	const float axis = Value.Get<float>();
	const int axisInt = static_cast<int>(axis);
	LogUtil::Log(FString::Printf(TEXT("X: %f, Y: %i"), axis, axisInt));
	const EBallMaterialType materialType = static_cast<EBallMaterialType>(axisInt);
	PossessedPawn->SwitchMaterial(materialType);
}
