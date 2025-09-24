// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "MyGameModeBase.generated.h"

class UUserWidget;

UCLASS()
class CPP_T_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AMyGameModeBase();

protected:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere)
	float Time;

	UPROPERTY(VisibleAnywhere)
	FString MyString;

	UFUNCTION(BlueprintCallable)
	FText GetMyString();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> MyWidgetClass;
};