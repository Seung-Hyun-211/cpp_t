// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Components/ArrowComponent.h"
#include "cpp_t/Public/Enemy.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	//��Ʈ ����
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	CurrentDelay = 2.0f;

	// ȭ��ǥ ����
	for (size_t i = 0; i < 5; i++)
	{
		FString str = "Arrow" + FString::FromInt(i);
		UArrowComponent* Arrow = CreateDefaultSubobject<UArrowComponent>(FName(str));

		//��ġ, ȸ�� ����
		double y = 100.0 - 50.0 * i;
		Arrow->SetRelativeLocation(FVector(0, y, 0));
		Arrow->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 0, 180)));
		Arrow->SetupAttachment(RootComponent);

		//TArray�� �߰�
		Arrows.Add(Arrow);
	}

	//���� �Ķ���� ���ʼ���, �浹����
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
}

//0.5�� ���� ���ο� ���� ����
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentDelay -= DeltaTime;
	
	if (CurrentDelay <= 0)
	{
		//���� UArrowComponent��ġ���� ����
		int randomIndex = FMath::RandRange(0, Arrows.Num()-1);

		AEnemy* newEnemy = GetWorld()->SpawnActor<AEnemy>(AEnemy::StaticClass(), Arrows[randomIndex]->GetRelativeTransform(), SpawnParams);
		CurrentDelay = 0.5f;
	}
}

