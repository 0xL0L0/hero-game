// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroGameInstance.h"

void UHeroGameInstance::Init()
{
	LevelManager = NewObject<ULevelManager>(GetWorld());
}