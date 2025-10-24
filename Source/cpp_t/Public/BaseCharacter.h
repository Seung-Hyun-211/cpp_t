
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
		int strength = 5;			//��
		int endurance = 5;			//����
		int agility = 5;			//��ø
		int intelligence = 5;		//����
		int physicalDefense = 5;	//�������
		int magicalResistance = 5;	//��������

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
		int maxHp = 100;				//�ִ� ü��
		int currentHp = 100;			//���� ü��
		int hpLimit = 0;				//ȸ�� ����
		int hpChangePerSec = 0;			//�ʴ� ü�� ��ȭ
		float recoverTime = 0.0f;		//�ʴ� ȸ�� �ð�Ȯ��
		bool isImmediateDamage = true;	//��� ����������
		bool isDead = false;			//���� ����

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
	/// ���� ü�� ����
	/// </summary>
	/// <param name="damage"></param>
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	/// <summary>
	/// �ִ� ü�� ����
	/// </summary>
	/// <param name="amount">������</param>
	/// <param name="withHeal">������ ��ŭ ȸ��</param>
	void AddMaxHp(int amount, bool withHeal = true);

	/// <summary>
	/// ü�� ȸ������ ����
	/// </summary>
	/// <param name="amount">��ȭ��</param>
	void AddLimit(int amount);

	/// <summary>
	/// �ð��� ���� ���� ü�� ����
	/// </summary>
	/// <param name="deltaTime">���� �ð�</param>
	void ChangeCurHpPerSec(float deltaTime);


private:
	/// <summary>
	/// currentHp ����
	/// </summary>
	/// <param name="amount">���� ��ġ</param>
	void AddCurHp(int amount);


private:
	Stat stat;
	Health health;

};