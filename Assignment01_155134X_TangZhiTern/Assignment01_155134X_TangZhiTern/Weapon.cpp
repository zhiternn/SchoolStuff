/******************************************************************************/
/*!
\file	Weapon.cpp
\author Tang Zhi Tern
\par	email: 155134X\@mymail.nyp.edu.sg
\brief
Class to define a weapon
*/
/******************************************************************************/

#include "Weapon.h"

/******************************************************************************/
/*!
\brief Parameter Constructor - Assigns required variables

\param kName
	Name of object
\param durability_
	durability of item
\param kSPECIAL
	attack value of weapon
*/
/******************************************************************************/
Weapon::Weapon(const string& kName, const int& durability_, const int& kAttackDmg) :
Item(kName, durability_),
kAttackDmg(kAttackDmg > 0 ? kAttackDmg : 0)
{
}

/******************************************************************************/
/*!
\brief Weapon virtual destructor
*/
/******************************************************************************/
Weapon::~Weapon()
{
}

/******************************************************************************/
/*!
\brief get attack value of weapon

\return attack value of weapon
*/
/******************************************************************************/
const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

/******************************************************************************/
/*!
\brief reduces durability of weapon
	
durability to be reduced is halved

\param damage
	damage to be taken by weapon
*/
/******************************************************************************/
void Weapon::receiveDamage(const int& damage)
{
	durability_ -= damage / 2;
	if (durability_ < 0){
		durability_ = 0;
	}
}