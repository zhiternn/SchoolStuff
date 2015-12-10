#include "Dweller.h"

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

Dweller::~Dweller()
{
}

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
const int Dweller::getCurrentHealth()
{
	return health_;
}
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}
const int Dweller::getAttackDmg()
{
	if (weapon_ == nullptr){
		return 1;
	}
	else{
		return weapon_->getAttackDmg();
	}
}
const Vec2D Dweller::getPosition()
{
	return position_;
}

void Dweller::setPosition(const Vec2D& position_)
{
	this->position_ = position_;
}

void Dweller::receiveHealthDamage(const int& health_)
{
	this->health_ -= health_;
}
void Dweller::receiveRadDamage(const int& radiation_)
{
	this->radiation_ += radiation_;
	if (health_ > currentMaxHealth()){
		health_ = currentMaxHealth();
	}
}
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

void Dweller::addStimpak(const int& stimpak_)
{
	this->stimpak_ += stimpak_;
}
void Dweller::addRadAway(const int& radaway_)
{
	this->radaway_ += radaway_;
}

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

int Dweller::currentMaxHealth(){
	return 100 - radiation_;
}