#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"

class Outfit : public Item{
public:
	Outfit(const string& kName, const int& durability_, const int& kSPECIAL);
	virtual ~Outfit();

	//GETTERS
	const int getSPECIAL();

	//SETTERS

	//ISTERS

	//OTHERS
	virtual void receiveDamage(const int& damage);
protected:

private:
	const int kSPECIAL;
};

#endif