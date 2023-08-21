// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroMenuMode.h"

#include "LogUtil.h"


void AHeroMenuMode::BeginPlay()
{
	LogUtil::Log(TEXT("BEGIN PLAY MODE"));
	Super::BeginPlay();
	MenuWidgetInstance = CreateWidget<UMainMenuWidget>(GetWorld(), MenuWidget);

	if(MenuWidgetInstance)
	{
		MenuWidgetInstance->AddToViewport();
	}
}

void AHeroMenuMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	if (MenuWidgetInstance)
	{
		MenuWidgetInstance->RemoveFromParent();
		MenuWidgetInstance = nullptr;
	}
}
