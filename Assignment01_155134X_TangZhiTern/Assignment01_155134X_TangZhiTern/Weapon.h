/******************************************************************************/
/*!
\file	Weapon.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class to define a weapon
*/
/******************************************************************************/

#ifndef	WEAPON_H
#define	WEAPON_H

#include "Item.h"

/****************************************************************************/
/*!
Class Outfit: public Item
\brief	a class that defines a weapon
*/
/****************************************************************************/
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