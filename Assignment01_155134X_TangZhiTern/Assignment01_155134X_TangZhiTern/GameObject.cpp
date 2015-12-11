/******************************************************************************/
/*!
\file	GameObject.cpp
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class to define a game object
*/
/******************************************************************************/

#include "GameObject.h"

int GameObject::count_ = 0;
/******************************************************************************/
/*!
\brief Parameter Constructor - Assign Name and count number of objects created

\param kName
	Name of object

\exception None
\return None
*/
/******************************************************************************/
GameObject::GameObject(const string& kName) :
kName(kName)
{
	count_++;
}

/******************************************************************************/
/*!
\brief	GameObject virtual destructor

Also counts number of objects deleted
*/
/******************************************************************************/
GameObject::~GameObject()
{
	count_--;
}

/****************************************************************************/
/*!
\brief Return the name of Object calling this function

\param None

\return
Name of Object
*/
/****************************************************************************/
string GameObject::getName(void)
{
	return kName;
}

/****************************************************************************/
/*!
\brief get number of objects existing in game 

\param None

\return
number of objects created
*/
/****************************************************************************/
int GameObject::getCount()
{
	return count_;
}