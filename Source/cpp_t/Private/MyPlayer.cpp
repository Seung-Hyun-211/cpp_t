// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

#include "MyPlayerController.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyPlayer::AMyPlayer()
{

	//박스 컴포넌트 추가, 루트설정
	box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = box;

	//메쉬 추가
	visualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	visualMesh->SetCollisionProfileName(TEXT("Player"));
	visualMesh->SetupAttachment(RootComponent);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(
		TEXT("/Engine/BasicShapes/Cube.Cube")
	);
	if (CubeAsset.Succeeded())
	{
		visualMesh->SetStaticMesh(CubeAsset.Object);
		visualMesh->SetWorldScale3D(FVector(1.3f)); // 크기 조정
	}

	//static ConstructorHelpers::FObjectFinder<UInputMappingContext>DEFAULT_CONTEXT
	//(TEXT("/Game/Inputs/IMC_Default"));
	//if (DEFAULT_CONTEXT.Succeeded())
	//{
	//	DefaultContext = DEFAULT_CONTEXT.Object;
	//}
	static ConstructorHelpers::FObjectFinder<UInputAction>IA_MOVE
	(TEXT("/Game/Input/IA_Move.IA_Move"));
	if (IA_MOVE.Succeeded())
	{
		MoveAction = IA_MOVE.Object;
	}
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();


	box->OnComponentBeginOverlap.AddDynamic(this, &AMyPlayer::OverlapBegin);
	box->OnComponentEndOverlap.AddDynamic(this, &AMyPlayer::OverlapEnd);

	moveSpeed = 20.0f;
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{	

		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))	
		{
			SubSystem->AddMappingContext(DefaultContext, 0);
			UE_LOG(LogTemp, Warning, TEXT("Added Mapping Context"));
		}
	}

}



// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}
void AMyPlayer::GetDamage(float Damage)
{

}
// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("Setup Input Component"));
	if (UEnhancedInputComponent * EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (!MoveAction)
		{
			UE_LOG(LogTemp, Error, TEXT("MoveAction not assigned in Blueprint!"));
			return;
		}

		UE_LOG(LogTemp, Warning, TEXT("Cast Complete"));
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayer::SetDirection);
	}
}
void AMyPlayer::PostInitializeComponents()
{
	UE_LOG(LogTemp, Warning, TEXT("Pawn Init"));
	Super::PostInitializeComponents();
}

void AMyPlayer::Move(float DeltaTime)
{
	FVector loc = GetActorLocation();
	loc += FVector(direction, 0.f) * moveSpeed * DeltaTime;

	SetActorLocation(loc);
}

void AMyPlayer::SetDirection(const FInputActionValue& InputValue)
{
	FVector2D MoveVector = InputValue.Get<FVector2D>();
	FString a = FString::Printf(TEXT("%f, %f"),MoveVector.X, MoveVector.Y);
	UE_LOG(LogTemp, Warning, TEXT("aaa %s"), *a);
	if (Controller != nullptr)
	{
		direction = MoveVector.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%f, %f"), direction.X, direction.Y);
	}
}

void AMyPlayer::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("End Overlap !!!"));
}

void AMyPlayer::OverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("!!! Begin Overlap"));
}
