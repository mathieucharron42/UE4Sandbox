// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DummyImageWidget.generated.h"

class UImage;
class UTexture2D;

/**
 * 
 */
UCLASS()
class SANDBOX_API UDummyImageWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Évènement déclenché en blueprint avertissant le controlleur c++ de passer à l'image suivante
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNextImageEvent);
	FNextImageEvent& OnNextImage() { return _nextImageEvent; }

	// Évènement déclenché en blueprint avertissant le controlleur c++ de passer à l'image précédente
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviousImageEvent);
	FPreviousImageEvent& OnPreviousImage() { return _previousImageEvent; }

	void SetImage(UTexture2D* image);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageWidget;
	
private:
	UPROPERTY(BlueprintCallable)
	FNextImageEvent _nextImageEvent;

	UPROPERTY(BlueprintCallable)
	FPreviousImageEvent _previousImageEvent;
};
