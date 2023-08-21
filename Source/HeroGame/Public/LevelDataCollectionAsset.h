// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEnums.h"
#include "LevelDataAsset.h"
#include "Engine/DataAsset.h"
#include "LevelDataCollectionAsset.generated.h"

/**
 * 
 */
UCLASS()
class HEROGAME_API ULevelDataCollectionAsset : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TMap<TEnumAsByte<ELevelType>, ULevelDataAsset*> LevelDataMap;

public:
	ULevelDataAsset* GetLevelDataAsset(TEnumAsByte<ELevelType> level);
};
