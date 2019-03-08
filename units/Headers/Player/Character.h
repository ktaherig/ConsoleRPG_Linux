#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

#include "../../Headers/Possessions/Inventory.h"

//(50/3) * (pow(x, 3) - 6*pow(x, 2) + (x * 17) - 12);

enum attributes { STRENGTH = 0, VITALITY, AGILITY, DEXTERITY, INTELLIGENCE};

class Character
{
private:
	//location
	unsigned x;
	unsigned y;

	//core
	std::string name;
	std::string bio;
	int level;
	int exp;
	int expNext;
	int statpoints;
	int location;

	//Stats
	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int mana;
	int manaMax;

	//attributes
	int strength; //Damage
	int vitality; //HP and stamina
	int agility; //Defence and doge chance
	int dexterity; //Hit chance and crit
	int intelligence; //Mana, magic find
	
	int damageMin;
	int damageMax;
	int defence;
	float hitRating;
	float critChance;
	float magicFind;

	int gold;

	//Flasks
	int flaskLevel;
	int flaskHeal;
	int flasks;
	int flasksMax;
	int flaskShards;
	int flaskShardsMax;

	//Skills

	//Weapon
	Weapon* weapon;

	//Armor
	Armor* armorHead;
	Armor* armorChest;
	Armor* armorShoulders;
	Armor* armorArms;
	Armor* armorLegs;

	//Inventory
	Inventory inventory;

	//Functions
	void updateStats();

public:
	Character(std::string name, std::string bio);
	virtual ~Character();

	//Accessors
	inline const unsigned getSeed() const { return this->x + this->y; };
	inline const unsigned getX() const { return this->x; }
	inline const unsigned getY() const { return this->y; }
	inline const int getLevel() const { return this->level; }
	inline const bool isDead() const { return this->hp <= 0; }
	inline const int getHP() const { return this->hp; }
	inline const int getHPMax() const { return this->hpMax; }
	inline const int getStamina() const { return this->stamina; }
	const int getDamageMin() const;
	const int getDamageMax() const;
	const int getDefence() const;
	inline const int getHitRating() const { return this->hitRating; }
	inline Inventory& getInventory() { return this->inventory; }
	const int getAttribute(const unsigned attribute);
	const int getTotalDamage() const;
	inline const int getLocation() const { return this->location; }
	Weapon* getWeapon();
	Armor* getArmor(int armor_type);

	//Modifiers
	void setLocation(const int location);
	void setPosition(const unsigned x, const unsigned y);
	void move(const int x, const int y);
	void setWeapon(Weapon* weapon);
	void setArmor(Armor* armor, const int armor_type);

	//Functions
	const std::string flee();
	void reset();
	void resetHP();
	void resetFlask();
	void addFlaskShard();
	bool upgradeFlask();
	bool consumeFlask();
	void takeDamage(const int damage);
	void setDead();
	bool addExp(const unsigned exp);
	void addGold(const unsigned gold);
	bool addStatpoint(const unsigned attribute);
	const std::string getMenuBar(const bool show_attributes = false);
	const std::string toString();
	const std::string toStringShort();
	const std::string toStringPosition();
	const std::string toStringNameBio();
	const std::string toStringEquipped() const;
	const std::string toStringStats() const;
};

#endif
