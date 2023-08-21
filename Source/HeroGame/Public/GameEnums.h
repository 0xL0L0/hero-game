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
