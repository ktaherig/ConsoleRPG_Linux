#ifndef WEAPON_H_
#define WEAPON_H_

#include "../../Headers/Possessions/Item.h"

class Weapon :
	public Item
{
private:
	int damageMax;
	int damageMin;

public:
	Weapon(unsigned level, unsigned rarity);

	Weapon(
		int damageMin,
		int damageMax,
		unsigned level,
		std::string name,
		unsigned type,
		unsigned rarity,
		unsigned value);

	virtual ~Weapon();

	//Accessors
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDamageMin() const { return this->damageMin; }

	//Functions
	Weapon* clone() const;
	const std::string toString() const;
};

#endif
