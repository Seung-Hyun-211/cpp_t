// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "MyPlayer.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	
	PrimaryActorTick.bCanEverTick = true;
		
	//박스 루트로 컴포넌트 추가
	box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	RootComponent = box;
	box->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	//프리셋 설정
	box->SetCollisionProfileName(TEXT("Enemy"));
	//외관설정
	BoxVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VIsualMesh"));
	BoxVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeAsset.Succeeded())
	{
		BoxVisual->SetStaticMesh(CubeAsset.Object);
		BoxVisual->SetWorldScale3D(FVector(0.8f));
	}
}

//void AEnemy::OverLapMyPlayer(AActor* OtherActor)
//{
//	AMyPlayer* other = Cast<AMyPlayer>(OtherActor);
//	if ( other )
//	{
//		other->GetDamage(1.0f);
//	}
//}


// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	box->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector newLocation = GetActorLocation() + FVector(-150.0f, 0.0f, 0.0f) * DeltaTime;
	SetActorLocation(newLocation);
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyPlayer* other = Cast<AMyPlayer>(OtherActor);
	if ( other )
	{
		other->GetDamage(1.0f);
	}
}
