/******************************************************************************/
/*!
\file	Outfit.cpp
\author Tang Zhi Tern
\par	email: 155134X\@mymail.nyp.edu.sg
\brief
Class to define an outfit
*/
/******************************************************************************/

#include "Outfit.h"

/******************************************************************************/
/*!
\brief Parameter Constructor - Assigns required variables

\param kName
	Name of object
\param durability_
	durability of item
\param kSPECIAL
	SPECIAL value of outfit
*/
/******************************************************************************/
Outfit::Outfit(const string& kName, const int& durability_, const int& kSPECIAL):
Item(kName, durability_),
kSPECIAL(kSPECIAL)
{
}

/******************************************************************************/
/*!
\brief Outfit virtual destructor
*/
/******************************************************************************/
Outfit::~Outfit()
{
}

/******************************************************************************/
/*!
\brief get SPECIAL value of outfit

\return SPECIAL value of outfit
*/
/******************************************************************************/
const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}

/******************************************************************************/
/*!
\brief reduces durability of outfit

\param damage
	damage to be taken by outfit
*/
/******************************************************************************/
void Outfit::receiveDamage(const int& damage)
{
	durability_ -= damage;
	if (durability_ < 0){
		durability_ = 0;
	}
}