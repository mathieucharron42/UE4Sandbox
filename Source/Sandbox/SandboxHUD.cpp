// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxHUD.h"
#include "DummyImageWidget.h"
#include "DummyImageWidgetController.h"

void ASandboxHUD::BeginPlay()
{
	Super::BeginPlay();
	if (_dummyImageWidgetClass)
	{
		// Créer le widget
		_dummyImageWidget = CreateWidget<UDummyImageWidget>(GetWorld(), _dummyImageWidgetClass);
		if (ensure(_dummyImageWidget))
		{
			// Ajouter au viewport
			_dummyImageWidget->AddToViewport();
		}

		// Créer le controller
		_dummyImageWidgetController = NewObject<UDummyImageWidgetController>(GetWorld(), _dummyImageWidgetControllerClass);
		if (ensure(_dummyImageWidgetController))
		{
			// Associer controller au widget
			_dummyImageWidgetController->SetWidget(_dummyImageWidget);
		}
	}
}