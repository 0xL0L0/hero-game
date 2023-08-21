// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuWidget.h"
#include "GameFramework/GameModeBase.h"
#include "HeroMenuMode.generated.h"

/**
 * 
 */
UCLASS()
class HEROGAME_API AHeroMenuMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY()
	UMainMenuWidget* MenuWidgetInstance;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> MenuWidget;
};
