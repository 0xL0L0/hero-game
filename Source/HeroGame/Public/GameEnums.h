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
	Paper UMETA(DisplayName = "Paper"),
	Rubber UMETA(DisplayName = "Rubber"),
	Wood UMETA(DisplayName = "Wood"),
	Stone UMETA(DisplayName = "Stone"),
	Metal UMETA(DisplayName = "Metal"),
	Glass UMETA(DisplayName = "Glass"),
	Plastic UMETA(DisplayName = "Plastic")
};