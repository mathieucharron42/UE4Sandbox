// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyImageWidget.h"

#include "Components/Image.h"
#include "Brushes/SlateImageBrush.h"


void UDummyImageWidget::SetImage(UTexture2D* image)
{
	if (ensure(ImageWidget))
	{
		FVector2D size(image->GetSizeX(), image->GetSizeY());
		FSlateImageBrush imageBrush = FSlateImageBrush(image, size);
		ImageWidget->SetBrush(imageBrush);
	}
}