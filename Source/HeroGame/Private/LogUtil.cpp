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
