// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "HeroGameInstance.h"
#include "LogUtil.h"
#include "Kismet/GameplayStatics.h"

void ULevelManager::GoToLevel(ELevelType levelType)
{
	const UWorld* world = GetWorld();
	
	if(LevelDataCollectionAsset == nullptr)
	{
		LevelDataCollectionAsset = Cast<UHeroGameInstance>(world->GetGameInstance())->LevelDataCollection;
	}
	
	UGameplayStatics::OpenLevelBySoftObjectPtr(world, LevelDataCollectionAsset->GetLevelDataAsset(levelType)->Level);
}
