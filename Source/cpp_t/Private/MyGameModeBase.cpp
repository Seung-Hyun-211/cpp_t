// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Engine/Engine.h"
#include "MyHUD.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"
#include "MyUserWidget.h"

#include "HealthSystem.h"


AMyGameModeBase::AMyGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	

	static ConstructorHelpers::FClassFinder<APlayerController> MyPlayerControllerClass(TEXT("/Game/MyMyPlayerController.MyMyPlayerController_C"));
	if (MyPlayerControllerClass.Succeeded())
	{
		PlayerControllerClass = MyPlayerControllerClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UMyUserWidget> MyWidget(TEXT("/Game/MyMyUserWidget.MyMyUserWidget_C"));
	if (MyWidget.Succeeded())
	{
		mainWidget = MyWidget.Class;
	}

	// APawn 타입으로 찾기
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/MyMyPlayer"));

	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		UE_LOG(LogTemp, Warning, TEXT("Pawn load!"));
	}
	else
	{
		DefaultPawnClass = AMyPlayer::StaticClass();
	}

	playerHp = new HealthSystem();
}

void AMyGameModeBase::BeginPlay()
{
	if (mainWidget != nullptr)
	{
		mainUI = CreateWidget<UMyUserWidget>(GetWorld(), mainWidget);
		if (mainUI != nullptr)
		{
			mainUI->AddToViewport();
		}
	}
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameMode Before"));
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("GameMode After"));
}

void AMyGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime;
	
	mainUI->MyTextBlock->SetText(FText::AsNumber(Time));
	CalculateHp(DeltaTime);
}

FText AMyGameModeBase::GetMyString()
{
	FString test = FString::Printf(TEXT("%.2f"), Time);
	return FText::FromString(test);
}

void AMyGameModeBase::CalculateHp(float fDeltatime)
{
	float beforeHp = playerHp->GetCurrentHp();
	bool isChanged = false;

	playerHp->ChangeCurHpPerSec(fDeltatime);

	if (isChanged)
	{
		//mainUI->SetHpStatus(playerHp->GetMaxHp(), playerHp->GetCurrentHp(), playerHp->GetHpLimit());
	}
}
