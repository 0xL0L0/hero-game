// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBallPawn.h"

#include "LogUtil.h"

// Sets default values
APlayerBallPawn::APlayerBallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBallPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerBallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerBallPawn::Roll(const FVector2d& inputAxis)
{
	auto normalizedInput = inputAxis.GetSafeNormal();
	
	auto debugString = FString::Printf(TEXT("X: %f, Y: %f"), normalizedInput.X, normalizedInput.Y);
	LogUtil::Log(debugString);
}

