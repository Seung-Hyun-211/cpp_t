// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MyPlayer.generated.h"

class UArrowComponent;
class UBoxComponent;

UCLASS()
class CPP_T_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();
	
	UPROPERTY(VisibleAnywhere, Category ="Components")
	UStaticMeshComponent* visualMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Arrow;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetDamage(float Damage);

	FVector2D direction;

	UPROPERTY(BlueprintReadOnly)
	float moveSpeed;
	void Move(float DeltaTime);
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent* box;
private:
	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputMappingContext* DefaultContext;

	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputAction* MoveAction;

	float Hp;
};
