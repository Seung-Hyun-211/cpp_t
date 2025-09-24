// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyPlayer::AMyPlayer()
{

	//박스 루트로 컴포넌트 추가
	box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	RootComponent = box;
	Hp = 10.0f;
	static ConstructorHelpers::FObjectFinder<UInputMappingContext>DEFAULT_CONTEXT
	(TEXT("/Game/Inputs/IMC_Default"));
	if (DEFAULT_CONTEXT.Succeeded())
	{
		DefaultContext = DEFAULT_CONTEXT.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction>IA_MOVE
	(TEXT("/Game/Inputs/IA_Move"));
	if (IA_MOVE.Succeeded())
	{
		MoveAction = IA_MOVE.Object;
	}
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	visualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("visualMesh"));
	visualMesh->SetCollisionProfileName(TEXT("Player"));
	visualMesh->SetupAttachment( RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(
		TEXT("/Engine/BasicShapes/Cube.Cube")
	);
	if (CubeAsset.Succeeded())
	{
		visualMesh->SetStaticMesh(CubeAsset.Object);
		visualMesh->SetWorldScale3D(FVector(1.f)); // 크기 조정
	}
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			SubSystem->AddMappingContext(DefaultContext, 0);
	}
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyPlayer::GetDamage(float Damage)
{
	Hp -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("current Hp : %f"),Hp);
}
// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPlayer::Move(float DeltaTime)
{
	FVector loc = GetActorLocation();
	loc += FVector(direction, 0.f) * moveSpeed * DeltaTime;

	SetActorLocation(loc);
}