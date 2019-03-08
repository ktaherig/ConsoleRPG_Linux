#include "../../Headers/Possessions/Weapon.h"

Weapon::Weapon(unsigned level, unsigned rarity)
	: Item(level, rarity, WEAPON)
{
	this->damageMin = (rand() % level + 1) + level;
	this->damageMax = (rand() % level + 1) + this->damageMin;
}

Weapon::Weapon(
	int damageMin,
	int damageMax,
	unsigned level,
	std::string name,
	unsigned type,
	unsigned rarity,
	unsigned value)
	: Item(level, name, type, rarity, value)
{
	this->damageMax = damageMax;
	this->damageMin = damageMin;
}

Weapon::~Weapon()
{

}

Weapon * Weapon::clone() const
{
	return new Weapon(*this);
}

const std::string Weapon::toString() const
{
	std::stringstream ss;

	ss << " | Name: " << this->getName()
		<< " | Type: " << this->getTypeAsString()
		<< " | Damage: " << this->damageMin << " - " << this->damageMax
		<< " | Rarity: " << this->getRarityAsString() //std::string(this->getRarity(), '*')
		<< " | Value: " << this->getValue();

	return ss.str();
}

//Functions
