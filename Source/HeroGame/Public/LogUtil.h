// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace LogUtil
{
	void Log(FString textToPrint);
	void LogWarning(FString textToPrint);
	void LogError(FString textToPrint);
	void Log(FVector vector);
}