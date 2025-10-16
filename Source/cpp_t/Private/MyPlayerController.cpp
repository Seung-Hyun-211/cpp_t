// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyUserWidget.h"

void AMyPlayerController::PostInitializeComponents()
{
	UE_LOG(LogTemp, Warning, TEXT("Contoller Init"));
	Super::PostInitializeComponents();
}

void AMyPlayerController::OnPossess(APawn* pawn)
{
	UE_LOG(LogTemp, Warning, TEXT("Controller Posess"));
	Super::OnPossess(pawn);
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}