// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace LogUtil
{
	void Log(FString TextToPrint);
	void LogWarning(FString TextToPrint);
	void LogError(FString TextToPrint);
}