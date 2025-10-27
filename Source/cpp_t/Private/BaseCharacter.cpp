#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	stat = FStat();
	health = FHealth();
}

void ABaseCharacter::InitializeStat(const FStat& st, const FHealth& he)
{
	stat = st;
	health = he;
}

void ABaseCharacter::InitializeStat(int str, int end, int agi, int intelli, int physicalDmg, int magicalDmg, int physicalDef, int magicalDef, int max, int current, int limit, int change, bool immediate)
{
	stat = FStat(str, end, agi, intelli, physicalDmg, magicalDmg, physicalDef, magicalDef);
	health = FHealth(max, current, limit, change, immediate);
}

ABaseCharacter::~ABaseCharacter()
{
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	ChangeCurHpPerSec(DeltaTime);
}

float ABaseCharacter::TakeDamage(float damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	AddCurHp(-damage);
	return Super::TakeDamage(damage, DamageEvent, EventInstigator, DamageCauser);
}

void ABaseCharacter::AddMaxHp(int amount, bool withHeal)
{
	if (health.maxHp + amount <= 0)
	{
		health.maxHp = 1;
		health.currentHp = 1;
	}
	else
	{
		health.maxHp += amount;
		health.currentHp += (withHeal ? amount : 0);
	}
}

void ABaseCharacter::AddLimit(int amount)
{
	if (health.hpLimit + amount >= health.maxHp)
	{
		health.hpLimit = health.maxHp - 1;
		health.currentHp = 1;
	}
	else if (health.hpLimit + amount < 1)
	{
		health.hpLimit = 0;
	}
	else
	{
		health.hpLimit += amount;
		health.currentHp = health.currentHp + health.hpLimit >= health.maxHp ? health.maxHp - health.hpLimit : health.currentHp;
	}
}

void ABaseCharacter::ChangeCurHpPerSec(float deltaTime)
{
	health.recoverTime += deltaTime;
	if (!health.isDead && health.recoverTime >= 1.0f)
	{
		health.recoverTime--;
		AddCurHp(health.hpChangePerSec);
	}
}

void ABaseCharacter::AddCurHp(int amount)
{
	int addedHp = health.currentHp + amount;
	if (addedHp <= 0)
	{
		health.currentHp = 0;
		health.isDead = true;
	}
	else if (addedHp >= health.maxHp - health.hpLimit)
	{
		health.currentHp = health.maxHp - health.hpLimit;;
	}
	else
	{
		health.currentHp = addedHp;
	}
}