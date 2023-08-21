// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/GameMode.h"
#include "LevelDataAsset.generated.h"


/**
 * 
 */
UCLASS()
class HEROGAME_API ULevelDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TSoftObjectPtr<UWorld> Level;
	UPROPERTY(EditAnywhere) TSubclassOf<AGameModeBase> GameMode;
};
