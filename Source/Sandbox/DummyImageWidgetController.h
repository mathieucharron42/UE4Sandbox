// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DummyImageWidgetController.generated.h"

class UDummyImageWidget;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class SANDBOX_API UDummyImageWidgetController : public UObject
{
	GENERATED_BODY()

public:
	void SetWidget(UDummyImageWidget* widget);

private:
	UFUNCTION()
	void OnNextImage();
	UFUNCTION()
	void OnPreviousImage();
	
	void UpdateImage();

	void RegisterWidgetEvents();
	void UnregisterWidgetEvents();

	UPROPERTY(Transient)
	UDummyImageWidget* _widget;

	UPROPERTY(Transient)
	int32 _currentImageIndex = 0;

	UPROPERTY(EditAnywhere, Category = "UI")
	TArray<UTexture2D*> _images;
};
