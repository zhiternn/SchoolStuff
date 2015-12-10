#include "Weapon.h"

Weapon::Weapon(const string& kName, const int& durability_, const int& kAttackDmg) :
Item(kName, durability_),
kAttackDmg(kAttackDmg)
{
}

Weapon::~Weapon()
{
}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

void Weapon::receiveDamage(const int& damage)
{
	durability_ -= damage / 2;
	if (durability_ < 0){
		durability_ = 0;
	}
}