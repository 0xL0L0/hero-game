// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "BallMaterialDataAsset.generated.h"
/**
 * 
 */
UCLASS()
class HEROGAME_API UBallMaterialData : public UDataAsset
{
	GENERATED_BODY()

public:
	// TODO - STORE PHYSICS MATERIAL. ADJUST BALANCING VALUES, AND INIT ON PLAYER BALL MAT SWITCH
	UPROPERTY(EditAnywhere, Category="Graphics") UMaterial* BaseMaterial;
	UPROPERTY(EditAnywhere, Category="Physics") UPhysicalMaterial* PhysicalMaterial;
	UPROPERTY(EditAnywhere, Category="Physics") float Mass;
	UPROPERTY(EditAnywhere, Category="Physics") float LinearDamping;
	UPROPERTY(EditAnywhere, Category="Physics") float AngularDamping;
	UPROPERTY(EditAnywhere, Category="Physics") float MovementRollForce;
	UPROPERTY(EditAnywhere, Category="Physics") float MovementJumpForce;
	UPROPERTY(EditAnywhere, Category="Physics") float MovementDashForce;
	UPROPERTY(EditAnywhere, Category="Physics") float MovementDashTime;;
	UPROPERTY(EditAnywhere, Category="Physics") float MovementAirControl;
	UPROPERTY(EditAnywhere, Category="Physics") float MaxAngularVelocity;

	// TODO - SET MAXIMUM LINEAR VELOCITY IN PLAYERBALL
	UPROPERTY(EditAnywhere, Category="Balancing") float MaxLinearVelocity;
	
};
