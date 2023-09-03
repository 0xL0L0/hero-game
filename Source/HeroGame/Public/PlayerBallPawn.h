// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BallMaterialDataAsset.h"
#include "GameEnums.h"
#include "HeroGameInstance.h"
#include "HeroGameMode.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerBallPawn.generated.h"

UCLASS()
class HEROGAME_API APlayerBallPawn : public APawn
{
	GENERATED_BODY()
	// Sets default values for this pawn's properties
	APlayerBallPawn();

	bool bIsGrounded;
	float JumpCooldown;

	void HandleTimers();
	void CheckUpdateGrounding();
	void ClampLinearVelocity() const;
	
	UPROPERTY()
	UHeroGameInstance* GameInstance;

	UPROPERTY()
	AHeroGameMode* GameMode;
	
	UPROPERTY()
	UBallMaterialData* CurrentBallMaterial;

	UPROPERTY()
	UStaticMeshComponent* BallComponent;

	UPROPERTY()
	USphereComponent* BallCollisionComponent;
	
	UPROPERTY()
	USpringArmComponent* CameraSpringArmComponent;

	UPROPERTY()
	UCameraComponent* CameraComponent;
	
	void CameraFollowBall();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, Category="Balancing")
	float CameraRotationSpeed;
	
	FVector MovementDirection;
	
	virtual void Tick(float DeltaTime) override;
	void Roll(const FVector2d& inputAxis);
	void Jump();
	void Dash(const FVector& direction);
	void RotateCamera(const float axis);
	void SwitchMaterial(const EBallMaterialType& materialType);
};
