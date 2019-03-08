#ifndef ARMOR_H_
#define ARMOR_H_

#include <sstream>
#include <string>
#include "../../Headers/Possessions/Item.h"

const unsigned NR_OF_ARMOR_TYPES = 5;
enum armor_types { ARMOR_HEAD = 0, ARMOR_CHEST, ARMOR_SHOULDERS, ARMOR_ARMS, ARMOR_LEGS};

class Armor :
	public Item
{
private:
	unsigned armorType;
	int defence;

public:
	Armor(unsigned level, unsigned rarity);

	Armor(
		int defence,
		unsigned armor_type,
		unsigned level,
		std::string name,
		unsigned type,
		unsigned rarity,
		unsigned value);

	virtual ~Armor();

	//Accessors
	inline const int& getArmorType() const { return this->armorType; }
	const std::string getArmorTypeAsString() const;
	inline const int& getDefence() const { return this->defence; }

	//Functions
	Armor* clone() const;
	const std::string toString() const;
};

#endif
