// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BallMaterialCollection.generated.h"

class UBallMaterialData;
enum class EBallMaterialType : uint8;
/**
 * 
 */
UCLASS()
class HEROGAME_API UBallMaterialCollection : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TMap<TEnumAsByte<EBallMaterialType>,UBallMaterialData*> BallMaterialMap;
public:
	UBallMaterialData* GetBallMaterial(const TEnumAsByte<EBallMaterialType>& materialType);
};
