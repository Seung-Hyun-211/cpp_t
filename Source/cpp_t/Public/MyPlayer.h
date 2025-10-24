// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/PrimitiveComponent.h"

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

	virtual void PostInitializeComponents() override;

	void GetDamage(float Damage);

	FVector2D direction;

	UPROPERTY(BlueprintReadOnly)
	float moveSpeed;
	void Move(float DeltaTime);
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent* box;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputMappingContext* DefaultContext;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* MoveAction;

	void SetDirection(const FInputActionValue& InputValue);


};
