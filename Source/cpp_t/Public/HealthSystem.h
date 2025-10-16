#pragma once

#include "CoreMinimal.h"

class CPP_T_API HealthSystem
{
public:
	HealthSystem(float max = 100.0f);
	~HealthSystem();


	//getter
	float GetMaximumHp() const { return maximumHp; }
	float GetCurrentHp() const { return currentHp; }
	float GetTemporaryHp() const { return temporaryHp; }
	float GetSacrificePercent() const { return sacrificePercent; }

	
	void IncreaseMaximumHp(float value);

private:
	float maximumHp;
	float currentHp;
	float temporaryHp;
	float sacrificePercent;

};
