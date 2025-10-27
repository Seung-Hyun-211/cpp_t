// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stat.h"
#include "Health.h"

struct Item
{
	enum Type {
		None = 0,
		Consume,
		Armor,
		Weapon,
	};

	Type type;
	int imgNum;
	FString itemName;
};

class CPP_T_API Inventory
{
public:
	Inventory();
	~Inventory();

private:
	TArray<Item*> itemSlots;
};
