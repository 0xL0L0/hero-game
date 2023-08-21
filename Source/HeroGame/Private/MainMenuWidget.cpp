// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "HeroGameInstance.h"
#include "LogUtil.h"
#include "Components/Button.h"

void UMainMenuWidget::PlayGame()
{
	LogUtil::Log(TEXT("CLICKED PLAY!"));
	Cast<UHeroGameInstance>(GetWorld()->GetGameInstance())->LevelManager->GoToLevel(ELevelType::Game);
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	PlayButton->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::PlayGame);
}

void UMainMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();

	PlayButton->OnClicked.RemoveDynamic(this, &UMainMenuWidget::PlayGame);
}

