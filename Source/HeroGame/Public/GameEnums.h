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
	Wood = 3 UMETA(DisplayName = "Wood"),
	Stone= 4 UMETA(DisplayName = "Stone"),
	Metal = 5 UMETA(DisplayName = "Metal"),
	Glass = 6 UMETA(DisplayName = "Glass"),
	Plastic = 7 UMETA(DisplayName = "Plastic")
};