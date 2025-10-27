// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stat.generated.h"

USTRUCT(BlueprintType)
struct FStat
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int strength;		//힘
	UPROPERTY()
	int endurance;		//지구
	UPROPERTY()
	int agility;		//민첩
	UPROPERTY()
	int intelligence;	//지능

	UPROPERTY()
	int physicalDamage; //물리데미지
	UPROPERTY()
	int magicalDamage;	//마법데미지

	UPROPERTY()
	int physicalDefense;//물리방어
	UPROPERTY()
	int magicalDefense;	//마법방어

	FStat()
	{
		strength = 0;
		endurance = 0;
		agility = 0;
		intelligence = 0;
		physicalDamage = 0;
		magicalDamage = 0;
		physicalDefense = 0;
		magicalDefense = 0;
	}

	FStat(int str, int end, int agi, int intelli, int physicalDmg, int magicalDmg, int physicalDef, int magicalDef) :
		strength(str),
		endurance(end),
		agility(agi),
		intelligence(intelli),
		physicalDamage(physicalDmg),
		magicalDamage(magicalDmg),
		physicalDefense(physicalDef),
		magicalDefense(magicalDef) {};

};