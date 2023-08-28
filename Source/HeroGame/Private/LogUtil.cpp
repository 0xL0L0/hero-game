// Fill out your copyright notice in the Description page of Project Settings.


#include "LogUtil.h"

void LogUtil::Log(FString textToPrint)
{
	UE_LOG(LogTemp, Log, TEXT("%s"),*textToPrint);
}

void LogUtil::LogWarning(FString textToPrint)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),*textToPrint);
}

void LogUtil::LogError(FString textToPrint)
{
	UE_LOG(LogTemp, Error, TEXT("%s"),*textToPrint);
}

void LogUtil::Log(FVector vector)
{
	auto debugString =  FString::Printf(TEXT("DASH X: %f, Y: %f Z: %f"), vector.X, vector.Y, vector.Z);
	Log(debugString);
}

