// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BallMaterialDataAsset.h"
#include "GameEnums.h"
#include "HeroGameInstance.h"
#include "HeroGameMode.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerBallPawn.generated.h"

UCLASS()
class HEROGAME_API APlayerBallPawn : public APawn
{
	GENERATED_BODY()
	// Sets default values for this pawn's properties
	APlayerBallPawn();

	UPROPERTY()
	UHeroGameInstance* GameInstance;

	UPROPERTY()
	AHeroGameMode* GameMode;
	
	UPROPERTY()
	UBallMaterialData* CurrentBallMaterial;

	UPROPERTY()
	UStaticMeshComponent* BallComponent;
	
	UPROPERTY()
	USpringArmComponent* CameraSpringArmComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
	void Roll(const FVector2d& inputAxis);
	void SwitchMaterial(const EBallMaterialType& materialType);
};