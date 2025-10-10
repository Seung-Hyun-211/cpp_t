// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Engine/Engine.h"
#include "MyHUD.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	PlayerControllerClass = AMyPlayerController::StaticClass();
	HUDClass = AMyHUD::StaticClass();

	// APawn 타입으로 찾기
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/MyMyPlayer"));

	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		UE_LOG(LogTemp, Warning, TEXT("✅ Blueprint Pawn loaded successfully!"));
	}
	else
	{
		DefaultPawnClass = AMyPlayer::StaticClass();
	}

}

void AMyGameModeBase::BeginPlay()
{

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
}

FText AMyGameModeBase::GetMyString()
{
	FString test = FString::Printf(TEXT("%.2f"), Time);
	return FText::FromString(test);
}
