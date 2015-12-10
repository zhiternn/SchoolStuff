#ifndef	WEAPON_H
#define	WEAPON_H

#include "Item.h"

class Weapon : public Item{
public:
	Weapon(const string& kName, const int& durability_, const int& kAttackDmg);
	virtual ~Weapon();

	//GETTERS
	const int getAttackDmg();

	//SETTERS

	//ISTERS

	//OTHERS
	virtual void receiveDamage(const int& damage);
protected:

private:

	const int kAttackDmg;
};

#endif