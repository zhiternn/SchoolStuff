/******************************************************************************/
/*!
\file	GameObject.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Counts and assign names to Objects existing in game
*/
/******************************************************************************/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

using std::string;

/****************************************************************************/
/*!
		Class GameObject:
\brief	Objects existing in game
*/
/****************************************************************************/
class GameObject
{
public:
	virtual ~GameObject();

	//GETTERS
	string getName(void);
	static int getCount();

	//SETTERS

	//ISTERS

	//OTHERS
protected:
	GameObject(const string& kName);

private:
	static int count_;
	const string kName;

};

#endif