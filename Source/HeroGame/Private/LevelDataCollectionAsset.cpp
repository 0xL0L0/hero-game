// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelDataCollectionAsset.h"

ULevelDataAsset* ULevelDataCollectionAsset::GetLevelDataAsset(TEnumAsByte<ELevelType> level)
{
	return LevelDataMap[level];
}