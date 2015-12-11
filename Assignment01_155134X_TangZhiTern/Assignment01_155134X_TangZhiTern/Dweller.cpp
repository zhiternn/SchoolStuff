/******************************************************************************/
/*!
\file	Dweller.cpp
\author Tang Zhi Tern
\par	email: 155134X@mymail.nyp.edu.sg
\brief
Class to define a Dweller and its methods
*/
/******************************************************************************/

#include "Dweller.h"

/******************************************************************************/
/*!
\brief
Parameter Constructor - Initializes all required variables

\param kName
	Name of object

\param SPECIAL_
	Stats unique to Dwellers

\exception None
\return None
*/
/******************************************************************************/
Dweller::Dweller(const string& kName, const int& SPECIAL_):
GameObject(kName),
position_(Vec2D(0, 0)),
SPECIAL_(SPECIAL_),
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
\brief
Get the total SPECIAL value of dweller

It will first check if there is an outfit equipped. 
If there is an outfit, it will calculate and return the sum of their special value.
Else, it will return just the special value of the dweller

\param None

\return
total value of Dweller and Outfit special value
*/
/****************************************************************************/
const int Dweller::getSPECIAL()
{
	if (outfit_){
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
\brief
Get the current health of dweller

\param None

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
\brief
get radiation damage inflicted to dweller

\param None

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

Default damage of dweller without a weapon is 1.

\param None

\return
attack damage of dweller
*/
/****************************************************************************/
const int Dweller::getAttackDmg()
{
	if (weapon_ == nullptr){
		return 1;
	}
	else{
		return weapon_->getAttackDmg();
	}
}

/****************************************************************************/
/*!
\brief get dweller's current position

\param None

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

\return None
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

\return None
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

\return None
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

Will remove equipment if it has no durability

\param damage
	damage to be taken by equipments

\return None
*/
/****************************************************************************/
void Dweller::receiveEquipmentDamage(const int& damage)
{
	if (weapon_){
		weapon_->receiveDamage(damage);
		if (weapon_->getDurability() == 0){
			weapon_ = nullptr;
		}
	}
	if (outfit_){
		outfit_->receiveDamage(damage);
		if (outfit_->getDurability() == 0){
			outfit_ = nullptr;
		}
	}
}

/****************************************************************************/
/*!
\brief gives Stimpaks to dweller

\param amount
	amount of Stimpaks to be given

\return None
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

\return None
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

\param None

\return None
*/
/****************************************************************************/
void Dweller::useStimpak()
{
	if (health_ + 20 > currentMaxHealth()){
		health_ = currentMaxHealth();
	}
	else{
		health_ += 20;
	}
	stimpak_--;
}

/****************************************************************************/
/*!
\brief uses RadAway on dweller calling this function

Will also reduce RadAway by one per call.
radiation will not go below 0

\param None

\return None
*/
/****************************************************************************/
void Dweller::useRadAway()
{
	if (radiation_ - 10 < 0){
		radiation_ = 0;
	}
	else{
		radiation_ -= 10;
	}
	radaway_--;
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

\param None

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

\param None

\return
max health of dweller
*/
/****************************************************************************/
int Dweller::currentMaxHealth(){
	return 100 - radiation_;
}