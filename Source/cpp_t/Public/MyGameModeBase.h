// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"


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

	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(VisibleAnywhere)
	float Time;

	UPROPERTY(VisibleAnywhere)
	FString MyString;

	UFUNCTION(BlueprintCallable)
	FText GetMyString();

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	//TSubclassOf<UUserWidget> WidgetClass;

};