// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Engine/Engine.h"
#include "MyPlayer.h"

AMyGameModeBase::AMyGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	DefaultPawnClass = AMyPlayer::StaticClass();

	//static ConstructorHelpers::FClassFinder<UUserWidget> WidgetBPClass(TEXT("Content\Level\TestWidget.uasset"));
	//if (WidgetBPClass.Class != nullptr)
	//{
	//	MyWidgetClass = WidgetBPClass.Class;
	//}
	//UUserWidget* Widget = CreateWidget<UUserWidget>(this, MyWidgetClass);
	
}

void AMyGameModeBase::BeginPlay()
{

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
