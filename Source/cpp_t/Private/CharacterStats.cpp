#include "CharacterStats.h"

CharacterStats::CharacterStats()
{
	stat = Stat();
	health = Health();
}

CharacterStats::CharacterStats(const Stat& st, const Health& he) :stat{ st }, health{he}
{
}

CharacterStats::CharacterStats(int str, int end, int agi, int intelli, int physical, int magical, int max, int current, int limit, int change, bool immediate)
{
	stat = Stat(str, end, agi, intelli, physical, magical);
	health = Health(max, current, limit, change, immediate);
}

CharacterStats::~CharacterStats()
{
}

void CharacterStats::TakeDamage(int damage)
{
	AddCurHp(-damage);
}

void CharacterStats::AddMaxHp(int amount, bool withHeal)
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

void CharacterStats::AddLimit(int amount)
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

void CharacterStats::ChangeCurHpPerSec(float deltaTime)
{
	health.recoverTime += deltaTime;
	if (!health.isDead && health.recoverTime >= 1.0f)
	{
		health.recoverTime--;
		AddCurHp(health.hpChangePerSec);
	}
}

void CharacterStats::AddCurHp(int amount)
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