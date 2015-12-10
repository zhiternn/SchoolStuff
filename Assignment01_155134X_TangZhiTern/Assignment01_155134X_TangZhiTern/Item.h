/******************************************************************************/
/*!
\file	Item.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class for item objects
*/
/******************************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

/****************************************************************************/
/*!
		Class Item: public GameObject
\brief	provides durability for items
*/
/****************************************************************************/
class Item : public GameObject{
public:
	Item(const string& kName, const int& durability_);
	virtual ~Item();

	//GETTERS
	const int getDurability();

	//SETTERS

	//ISTERS

	//OTHERS
	virtual void receiveDamage(const int& damage) = 0;

protected:
	int durability_;

private:

};

#endif