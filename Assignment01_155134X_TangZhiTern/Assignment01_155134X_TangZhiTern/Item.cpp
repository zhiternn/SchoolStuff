/******************************************************************************/
/*!
\file	Item.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class for item objects
*/
/******************************************************************************/

#include "Item.h"

/******************************************************************************/
/*!
\brief
Parameter Constructor - Assign name and durability to an item

\param kName
	Name of object
\param durability_
	durability of item

\exception None
\return None
*/
/******************************************************************************/
Item::Item(const string& kName, const int& durability_):
GameObject(kName),
durability_(durability_)
{
}

/****************************************************************************/
/*!
\brief Item virtual destructor
*/
/****************************************************************************/
Item::~Item()
{
}

/******************************************************************************/
/*!
\brief get durability of item calling this function

\param None

\exception None
\return item durability
*/
/******************************************************************************/
const int Item::getDurability()
{
	return durability_;
}