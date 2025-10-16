// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

void UMyUserWidget::SetBlockText(const FText InputText)
{
	if (MyTextBlock)
	{
		MyTextBlock->SetText(InputText);
	}
}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
