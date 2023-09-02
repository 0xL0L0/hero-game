// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ELevelType : uint8
{
	Loading UMETA(DisplayName = "Loading"),
	MainMenu UMETA(DisplayName = "Main Menu"),
	Game UMETA(DisplayName = "Game")
};

UENUM(BlueprintType)
enum class EBallMaterialType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Paper = 1 UMETA(DisplayName = "Paper"),
	Rubber = 2 UMETA(DisplayName = "Rubber"),
	Plastic = 3 UMETA(DisplayName = "Plastic"),
	Wood = 4 UMETA(DisplayName = "Wood"),
	Glass = 5 UMETA(DisplayName = "Glass"),
	Metal = 6 UMETA(DisplayName = "Metal"),
	Stone= 7 UMETA(DisplayName = "Stone")
};