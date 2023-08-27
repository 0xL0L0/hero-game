// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BallMaterialCollection.h"
#include "LevelManager.h"
#include "Engine/GameInstance.h"
#include "HeroGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HEROGAME_API UHeroGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	UPROPERTY() ULevelManager* LevelManager;
	UPROPERTY(EditAnywhere) ULevelDataCollectionAsset* LevelDataCollection;
	UPROPERTY(EditAnywhere) UBallMaterialCollection* BallMaterialCollection;
};
