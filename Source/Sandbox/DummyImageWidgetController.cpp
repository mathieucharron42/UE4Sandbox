// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyImageWidgetController.h"

#include "DummyImageWidget.h"

void UDummyImageWidgetController::SetWidget(UDummyImageWidget* widget)
{
	if (widget)
	{
		_widget = widget;
		RegisterWidgetEvents();
		UpdateImage();
	}
	else
	{
		_widget = nullptr;
		UnregisterWidgetEvents();
	}
}

void UDummyImageWidgetController::RegisterWidgetEvents()
{
	// Éviter enregistrements multiples
	UnregisterWidgetEvents();

	if (_widget)
	{
		_widget->OnNextImage().AddDynamic(this, &UDummyImageWidgetController::OnNextImage);
		_widget->OnPreviousImage().AddDynamic(this, &UDummyImageWidgetController::OnPreviousImage);
	}
}

void UDummyImageWidgetController::UnregisterWidgetEvents()
{
	if (_widget)
	{
		_widget->OnNextImage().RemoveAll(this);
		_widget->OnPreviousImage().RemoveAll(this);
	}
}

void UDummyImageWidgetController::OnNextImage()
{
	if (_images.Num() > 0)
	{
		_currentImageIndex = (_currentImageIndex + 1) % _images.Num();
		UpdateImage();
	}
}

void UDummyImageWidgetController::OnPreviousImage()
{
	if (_images.Num() > 0)
	{
		_currentImageIndex = ((_currentImageIndex - 1) + _images.Num()) % _images.Num();
		UpdateImage();
	}
}

void UDummyImageWidgetController::UpdateImage()
{
	UE_LOG(LogTemp, Log, TEXT("%i"), _currentImageIndex);
	if (_currentImageIndex < _images.Num())
	{
		UTexture2D* currentImage = _images[_currentImageIndex];
		_widget->SetImage(currentImage);
	}
}