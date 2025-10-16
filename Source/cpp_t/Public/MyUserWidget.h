// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPP_T_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "UserWidget")
	TSubclassOf<UUserWidget> UserWidget;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* MyTextBlock;

	UFUNCTION(BlueprintCallable)
	void SetBlockText(const FText InputText);

	virtual void NativeConstruct() override;

};
