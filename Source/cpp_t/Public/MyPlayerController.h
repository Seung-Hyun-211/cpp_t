// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CPP_T_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:


public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* pawn) override;
	virtual void BeginPlay() override;

	void UpdateHealth(const FText& newHealth);

	//UFUNCTION(BlueprintImplementableEvent, Category = "UI")
	//void UpdateHealth(const FText& NewHealth);

	//UPROPERTY(EditAnywhere)
	//TSubclassOf<UUserWidget> WidgetClass;

};
