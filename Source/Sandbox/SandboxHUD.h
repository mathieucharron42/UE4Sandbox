// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SandboxHUD.generated.h"

class UDummyImageWidget;
class UDummyImageWidgetController;

/**
 * 
 */
UCLASS()
class SANDBOX_API ASandboxHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UDummyImageWidget> _dummyImageWidgetClass;

	UPROPERTY(Transient)
	UDummyImageWidget* _dummyImageWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UDummyImageWidgetController> _dummyImageWidgetControllerClass;

	UPROPERTY(Transient)
	UDummyImageWidgetController* _dummyImageWidgetController;
};
