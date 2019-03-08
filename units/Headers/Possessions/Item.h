#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <sstream>

const unsigned NR_OF_ITEM_RARITIES = 6;

enum item_types {WEAPON = 0, ARMOR};
enum item_rarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC};

class Item
{
private:
	unsigned level;
	std::string name;
	unsigned type;
	unsigned rarity;
	unsigned value;

	void generate();

public:
	Item(unsigned level, unsigned rarity, unsigned type);

	Item(
		unsigned level,
		std::string name,
		unsigned type,
		unsigned rarity,
		unsigned value);
	virtual ~Item();

	//Accessors
	const unsigned& getLevel() const;
	const std::string& getName() const;
	const unsigned& getType() const;
	const std::string getTypeAsString() const;
	const unsigned& getRarity() const;
	const std::string getRarityAsString() const;
	const unsigned& getValue() const;

	//Functions
	virtual Item* clone() const = 0;
	virtual const std::string toString() const = 0;
};

#endif
