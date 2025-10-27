// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Health.generated.h"

USTRUCT()
struct FHealth
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY()
	int maxHp ;				//최대 체력
	UPROPERTY()
	int currentHp ;			//현재 체력
	UPROPERTY()
	int hpLimit ;			//회복 제한
	UPROPERTY()
	int hpChangePerSec ;	//초당 체력 변화
	UPROPERTY()
	float recoverTime ;		//초당 회복 시간확인
	UPROPERTY()
	bool isImmediateDamage ;//즉시 데미지받음
	UPROPERTY()
	bool isDead ;			//죽은 상태

	FHealth()
	{
		maxHp = 100;
		currentHp = 100;
		hpLimit = 0;
		hpChangePerSec = 0;
		recoverTime = 0.0f;
		isImmediateDamage = true;
		isDead = false;
	}

	FHealth(int max, int current, int limit, int change, bool immediate) :
		maxHp ( max ),
		currentHp ( current ),
		hpLimit ( limit ),
		hpChangePerSec ( change ),
		recoverTime ( 0.0f ),
		isImmediateDamage ( immediate ),
		isDead ( false ) { };
	
};