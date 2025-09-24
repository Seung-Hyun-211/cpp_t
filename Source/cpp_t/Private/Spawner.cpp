// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Components/ArrowComponent.h"
#include "cpp_t/Public/Enemy.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	//루트 생성
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	CurrentDelay = 2.0f;

	// 화살표 생성
	for (size_t i = 0; i < 5; i++)
	{
		FString str = "Arrow" + FString::FromInt(i);
		UArrowComponent* Arrow = CreateDefaultSubobject<UArrowComponent>(FName(str));

		//위치, 회전 설정
		double y = 100.0 - 50.0 * i;
		Arrow->SetRelativeLocation(FVector(0, y, 0));
		Arrow->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 0, 180)));
		Arrow->SetupAttachment(RootComponent);

		//TArray에 추가
		Arrows.Add(Arrow);
	}

	//스폰 파라미터 오너설정, 충돌무시
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
}

//0.5초 마다 새로운 적을 생성
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentDelay -= DeltaTime;
	
	if (CurrentDelay <= 0)
	{
		//랜덤 UArrowComponent위치에서 생성
		int randomIndex = FMath::RandRange(0, Arrows.Num()-1);

		AEnemy* newEnemy = GetWorld()->SpawnActor<AEnemy>(AEnemy::StaticClass(), Arrows[randomIndex]->GetRelativeTransform(), SpawnParams);
		CurrentDelay = 0.5f;
	}
}

