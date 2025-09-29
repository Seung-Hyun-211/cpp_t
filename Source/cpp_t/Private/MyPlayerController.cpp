// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
void AMyPlayerController::PostInitializeComponents()
{
	UE_LOG(LogTemp, Warning, TEXT("Contoller Init"));
	Super::PostInitializeComponents();

	//static ConstructorHelpers::FClassFinder<UUserWidget>TestWidget(TEXT("/Game/Level/TestWidget"));
	//if (TestWidget.Succeeded())
	//{
	//	WidgetClass = TestWidget.Class;
	//}

}

void AMyPlayerController::OnPossess(APawn* pawn)
{
	UE_LOG(LogTemp, Warning, TEXT("Controller Posess"));
	Super::OnPossess(pawn);
}

void AMyPlayerController::BeginPlay()
{
	//if (WidgetClass != nullptr)
	//{
	//	UUserWidget* MyWidget = CreateWidget<UUserWidget>(this, WidgetClass);
	//	if (MyWidget)
	//	{
	//		MyWidget->AddToViewport();
	//		//AMyPlayer* Player = Cast<AMyPlayer>(GetPawn());
	//		//if (Player != nullptr)
	//		//{
	//		//	Player->SetHUD(MyWidget);
	//		//}
	//	}
	//}
}