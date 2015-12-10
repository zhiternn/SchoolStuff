/******************************************************************************/
/*!
\file	GameObject.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Counts and assign names to Objects existing in game
*/
/******************************************************************************/
#include "GameObject.h"

int GameObject::count_ = 0;
/******************************************************************************/
/*!
\brief
Parameter Constructor - Also counts number of objects created

\param kName - Name of object

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
\brief
Destructor - Also counts number of objects deleted

\param None

\exception None
\return None
*/
/******************************************************************************/
GameObject::~GameObject()
{
	count_--;
}

/****************************************************************************/
/*!
\brief
Return the name of Object calling this function
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
\brief
Return number of objects existing in game 
\return
Name of Object
*/
/****************************************************************************/
int GameObject::getCount()
{
	return count_;
}