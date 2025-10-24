
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseCharacter.generated.h"

UCLASS()
class CPP_T_API ABaseCharacter :public APawn
{
	GENERATED_BODY()

public:
	struct Stat
	{
		int strength = 5;			//힘
		int endurance = 5;			//지구
		int agility = 5;			//민첩
		int intelligence = 5;		//지능
		int physicalDefense = 5;	//물리방어
		int magicalResistance = 5;	//마법저항

		Stat() = default;
		Stat(int str, int end, int agi, int intelli, int physical, int magical) :
			strength{ str },
			endurance{ end },
			agility{ agi },
			intelligence{ intelli },
			physicalDefense{ physical },
			magicalResistance{ magical } {
		};

	};

	struct Health
	{
		int maxHp = 100;				//최대 체력
		int currentHp = 100;			//현재 체력
		int hpLimit = 0;				//회복 제한
		int hpChangePerSec = 0;			//초당 체력 변화
		float recoverTime = 0.0f;		//초당 회복 시간확인
		bool isImmediateDamage = true;	//즉시 데미지받음
		bool isDead = false;			//죽은 상태

		Health() = default;
		Health(int max, int current, int limit, int change, bool immediate) :
			maxHp{ max },
			currentHp{ current },
			hpLimit{ limit },
			hpChangePerSec{ change },
			recoverTime{ 0.0f },
			isImmediateDamage{ immediate } {}
		};

	ABaseCharacter();
	~ABaseCharacter();

	void InitializeStat(const Stat& st, const Health& he);
	void InitializeStat(int str, int end, int agi, int intelli, int physical, int magical, int max, int current, int limit, int change, bool immediate);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;



public:

	//stat getter
	int GetStrength() const { return stat.strength; }
	int GetEndurance() const { return stat.endurance; }
	int GetAgility() const { return stat.agility; }
	int GetIntelligence() const { return stat.intelligence; }
	int GetPhysicalDefense() const { return stat.physicalDefense; }
	int GetMagicalResistance() const { return stat.magicalResistance; }

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
	/// <summary>
	/// currentHp 증감
	/// </summary>
	/// <param name="amount">증감 수치</param>
	void AddCurHp(int amount);


private:
	Stat stat;
	Health health;

};