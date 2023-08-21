// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class HEROGAME_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* PlayButton;

private:
	UFUNCTION()
	void PlayGame();
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
};
