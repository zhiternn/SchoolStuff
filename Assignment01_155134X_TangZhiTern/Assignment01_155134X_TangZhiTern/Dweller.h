/******************************************************************************/
/*!
\file	Dweller.h
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class to define a Dweller and its methods
*/
/******************************************************************************/

#ifndef DWELLER_H
#define DWELLER_H

#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

/****************************************************************************/
/*!
Class Dweller: public GameObject
\brief	Provides variables and methods for Dweller Object
*/
/****************************************************************************/
class Dweller : public GameObject{

public:
	Dweller(const string& kName, const int& SPECIAL_ = 0);
	virtual ~Dweller();

	//GETTERS
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	const Vec2D getPosition();

	//SETTERS
	void setPosition(const Vec2D& position_);

	//ISTERS
	bool isDead();

	//OTHERS
	void receiveHealthDamage(const int& damage);		
	void receiveRadDamage(const int& radiation_);		
	void receiveEquipmentDamage(const int& damage);

	void addStimpak(const int& amount);
	void addRadAway(const int& amount);

	void useStimpak();									
	void useRadAway();

	Outfit* assignOutfit(Outfit* outfit_);
	Weapon* assignWeapon(Weapon* weapon_);

	int currentMaxHealth();

protected:

private:

	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;
};

#endif