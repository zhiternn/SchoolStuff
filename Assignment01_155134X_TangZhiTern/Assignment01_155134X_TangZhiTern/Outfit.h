/******************************************************************************/
/*!
\file	Outfit.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class to define an outfit
*/
/******************************************************************************/

#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"

/****************************************************************************/
/*!
		Class Outfit: public Item
\brief	a class that defines an outfit
*/
/****************************************************************************/
class Outfit : public Item{
public:
	Outfit(const string& kName, const int& durability_, const int& kSPECIAL);
	virtual ~Outfit();

	//GETTERS
	const int getSPECIAL();

	//SETTERS

	//ISTERS

	//OTHERS
	virtual void receiveDamage(const int& damage);
protected:

private:
	const int kSPECIAL;
};

#endif