#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

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