
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Stat.h"
#include "Health.h"
#include "BaseCharacter.generated.h"

UCLASS()
class CPP_T_API ABaseCharacter :public APawn
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	~ABaseCharacter();


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	//virtual void Attack();


public:
	void InitializeStat(const FStat& st, const FHealth& he);
	void InitializeStat(int str, int end, int agi, int intelli, int physicalDmg, int magicalDmg, int physicalDef, int magicalDef, int max, int current, int limit, int change, bool immediate);


public:
	//stat getter
	int GetStrength() const { return stat.strength; }
	int GetEndurance() const { return stat.endurance; }
	int GetAgility() const { return stat.agility; }
	int GetIntelligence() const { return stat.intelligence; }

	int GetPhysicalDamage() const { return stat.physicalDamage; }
	int GetMagicalDamage() const { return stat.magicalDamage; }

	int GetPhysicalDefense() const { return stat.physicalDefense; }
	int GetMagicalResistance() const { return stat.magicalDefense; }

	//health getter
	int GetMaxHp() const { return health.maxHp;	}
	int GetCurrentHp() const { return health.currentHp; }
	int GetHpLimit() const { return health.hpLimit; }
	int GetChangePerSec() const { return health.hpChangePerSec; }
	bool IsDead() const { return health.isDead; }

	/// <summary>
	/// 현재 체력 감소
	/// </summary>
	/// <param name="damage"></param>
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	/// <summary>
	/// 최대 체력 증감
	/// </summary>
	/// <param name="amount">증가량</param>
	/// <param name="withHeal">증가량 만큼 회복</param>
	void AddMaxHp(int amount, bool withHeal = true);

	/// <summary>
	/// 체력 회복제한 증감
	/// </summary>
	/// <param name="amount">변화량</param>
	void AddLimit(int amount);

	/// <summary>
	/// 시간에 의한 현재 체력 증감
	/// </summary>
	/// <param name="deltaTime">지난 시간</param>
	void ChangeCurHpPerSec(float deltaTime);


private:
	FStat stat;
	FHealth health;

private:
	/// <summary>
	/// currentHp 증감
	/// </summary>
	/// <param name="amount">증감 수치</param>
	void AddCurHp(int amount);

};