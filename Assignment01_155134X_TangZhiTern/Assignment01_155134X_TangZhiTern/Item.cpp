#include "Item.h"

Item::Item(const string& kName, const int& durability_):
GameObject(kName),
durability_(durability_)
{
}

Item::~Item()
{
}

const int Item::getDurability()
{
	return durability_;
}