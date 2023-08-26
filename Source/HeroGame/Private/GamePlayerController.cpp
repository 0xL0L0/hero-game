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
	
	enhancedInput->BindAction(RollAction, ETriggerEvent::Triggered, this, &AGamePlayerController::HandleRollInput);
}

void AGamePlayerController::HandleRollInput(const FInputActionValue& Value)
{
	const FVector2d rollVector = Value.Get<FVector2d>();

	PossessedPawn->Roll(rollVector);
}
