// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemWidget.generated.h"

class UImage;

UCLASS()
class CPP_T_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UItemWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* SlotImage;
};
