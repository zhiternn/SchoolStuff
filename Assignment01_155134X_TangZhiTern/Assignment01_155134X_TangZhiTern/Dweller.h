#ifndef DWELLER_H
#define DWELLER_H

#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

class Dweller : public GameObject{

public:
	Dweller(const string& kName, const int& SPECIAL_);
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
	void receiveHealthDamage(const int& health_);		
	void receiveRadDamage(const int& radiation_);		
	void receiveEquipmentDamage(const int& damage);

	void addStimpak(const int& stimpak_);
	void addRadAway(const int& radaway_);

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