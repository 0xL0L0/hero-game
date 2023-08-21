// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelDataCollectionAsset.h"
#include "UObject/NoExportTypes.h"
#include "LevelManager.generated.h"

/**
 * 
 */
UCLASS()
class HEROGAME_API ULevelManager : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY()
	ULevelDataCollectionAsset* LevelDataCollectionAsset;

public:
	void GoToLevel(ELevelType levelType);
	
};
