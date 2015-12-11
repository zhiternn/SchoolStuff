/******************************************************************************/
/*!
\file	Dweller.cpp
\author Tang Zhi Tern
\par	email: 155134X\@mymail.nyp.edu.sg
\brief Class to define a Dweller and its methods
*/
/******************************************************************************/

#include "Dweller.h"

/******************************************************************************/
/*!
\brief Parameter Constructor - Initializes all required variables

\param kName
	Name of object

\param SPECIAL_
	Stats unique to Dwellers
*/
/******************************************************************************/
Dweller::Dweller(const string& kName, const int& SPECIAL_):
GameObject(kName),
position_(Vec2D(0, 0)),
SPECIAL_(SPECIAL_ > 0 ? SPECIAL_ : 0),
health_(100),
radiation_(0),
stimpak_(0),
radaway_(0),
outfit_(nullptr),
weapon_(nullptr)
{
}

/******************************************************************************/
/*!
\brief	GameObject virtual destructor
*/
/******************************************************************************/
Dweller::~Dweller()
{
}

/****************************************************************************/
/*!
\brief Get the total SPECIAL value of dweller

It will first check if there is an outfit equipped and durability is > 0 
If there is an outfit, it will calculate and return the sum of their special value.
Else, it will return just the special value of the dweller

\return
total value of Dweller and Outfit special value
*/
/****************************************************************************/
const int Dweller::getSPECIAL()
{
	if (outfit_ && outfit_->getDurability() > 0){
		int outfitSPECIAL = outfit_->getSPECIAL();
		int dwellerSPECIAL = SPECIAL_;
		int pow = 1;
		int totalSPECIAL = 0;

		for (size_t i = 0; i < 7; ++i){
			if (outfitSPECIAL % 10 + dwellerSPECIAL % 10 > 9){
				totalSPECIAL += 9 * pow;
			}
			else{
				totalSPECIAL += ((outfitSPECIAL % 10) + (dwellerSPECIAL % 10)) * pow;
			}

			outfitSPECIAL /= 10;
			dwellerSPECIAL /= 10;
			pow *= 10;
		}
		return totalSPECIAL;
	}
	else{
		return SPECIAL_;
	}
}
/****************************************************************************/
/*!
\brief Get the current health of dweller

\return
current health of dweller
*/
/****************************************************************************/
const int Dweller::getCurrentHealth()
{
	return health_;
}

/****************************************************************************/
/*!
\brief get radiation damage inflicted to dweller

\return
Current radiation damage of dweller
*/
/****************************************************************************/
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

/****************************************************************************/
/*!
\brief get attack damage of dweller

It will first check if dweller has a weapon and weapon durability > 0.
Else, it will return a default damage of 1.

\return
attack damage of dweller
*/
/****************************************************************************/
const int Dweller::getAttackDmg()
{
	if (weapon_ && weapon_->getDurability() > 0){
		return weapon_->getAttackDmg();
	}
	else{
		return 1;
	}
}

/****************************************************************************/
/*!
\brief get dweller's current position

\return
position vector of dweller's position
*/
/****************************************************************************/
const Vec2D Dweller::getPosition()
{
	return position_;
}

/****************************************************************************/
/*!
\brief set the dweller's current position

\param position_
	Position of dweller to be set to
*/
/****************************************************************************/
void Dweller::setPosition(const Vec2D& position_)
{
	this->position_ = position_;
}

/****************************************************************************/
/*!
\brief reduces dweller current health

\param damage
	damage to be taken
*/
/****************************************************************************/
void Dweller::receiveHealthDamage(const int& damage)
{
	this->health_ -= damage;
}

/****************************************************************************/
/*!
\brief increases radiation amount of dweller

Will also set dweller's current health if its higher than its max health after radiation damage

\param radiation_
	radiation damage taken by dweller
*/
/****************************************************************************/
void Dweller::receiveRadDamage(const int& radiation_)
{
	this->radiation_ += radiation_;
	if (health_ > currentMaxHealth()){
		health_ = currentMaxHealth();
	}
}

/****************************************************************************/
/*!
\brief reduces durability of equipment of dweller

\param damage
	damage to be taken by equipments
*/
/****************************************************************************/
void Dweller::receiveEquipmentDamage(const int& damage)
{
	if (weapon_)
		weapon_->receiveDamage(damage);
	if (outfit_)
		outfit_->receiveDamage(damage);
}

/****************************************************************************/
/*!
\brief gives Stimpaks to dweller

\param amount
	amount of Stimpaks to be given
*/
/****************************************************************************/
void Dweller::addStimpak(const int& amount)
{
	this->stimpak_ += amount;
}

/****************************************************************************/
/*!
\brief gives RadAway to dweller

\param amount
	amount of RadAway to be given
*/
/****************************************************************************/
void Dweller::addRadAway(const int& amount)
{
	this->radaway_ += amount;
}

/****************************************************************************/
/*!
\brief uses Stimpak on dweller calling this function

Will also reduce Stimpak by one per call.
current health will not go over max health
*/
/****************************************************************************/
void Dweller::useStimpak()
{
	if (stimpak_ > 0){
		if (health_ + 20 > currentMaxHealth()){
			health_ = currentMaxHealth();
		}
		else{
			health_ += 20;
		}
		stimpak_--;
	}
}

/****************************************************************************/
/*!
\brief uses RadAway on dweller calling this function

Will also reduce RadAway by one per call.
radiation will not go below 0
*/
/****************************************************************************/
void Dweller::useRadAway()
{
	if (radaway_ > 0){
		if (radiation_ - 10 < 0){
			radiation_ = 0;
		}
		else{
			radiation_ -= 10;
		}
		radaway_--;
	}
}

/****************************************************************************/
/*!
\brief assigns dweller with a new outfit

will not attempt to equip if outfit has no durability

\param outfit_
	outfit to be equipped

\return 
	old outfit that was unequipped
*/
/****************************************************************************/
Outfit* Dweller::assignOutfit(Outfit* outfit_)
{
	if (outfit_->getDurability() > 0){
		Outfit* oldOutfit(this->outfit_);
		this->outfit_ = outfit_;
		return oldOutfit;
	}
	else{
		return outfit_;
	}
}

/****************************************************************************/
/*!
\brief assigns dweller with a new weapon

will not attempt to equip if weapon has no durability

\param weapon_
	weapon to be equipped

\return
old weapon that was unequipped
*/
/****************************************************************************/
Weapon* Dweller::assignWeapon(Weapon* weapon_)
{
	if (weapon_->getDurability() > 0){
		Weapon* oldWeapon(this->weapon_);
		this->weapon_ = weapon_;
		return oldWeapon;
	}
	else{
		return weapon_;
	}
}

/****************************************************************************/
/*!
\brief checks if dweller is dead

will unequip equipment for dweller if its dead

\return
bool to determine death
*/
/****************************************************************************/
bool Dweller::isDead()
{
	if (health_ <= 0){
		weapon_ = nullptr;
		outfit_ = nullptr;
		return true;
	}
	else{
		return false;
	}
}

/****************************************************************************/
/*!
\brief calculates the max available health a dweller can have

\return
max health of dweller
*/
/****************************************************************************/
int Dweller::currentMaxHealth(){
	return 100 - radiation_;
}