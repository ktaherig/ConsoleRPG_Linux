#include "../../Headers/Player/Enemy.h"

Enemy::Enemy(int level, int drop_chance)
{
	this->level = level;
	this->hpMax = level * 10 + this->level;
	this->hp = this->hpMax;

	this->damageMin = this->level * 2;
	this->damageMax = this->level + this->level * 2;
	this->defence = this->level * 2;
	this->hitRating = this->level * 2 + this->level;
	this->critChance = static_cast<float>(this->level) / 60;

	this->dropChance = drop_chance;
}

Enemy::~Enemy()
{

}



//functions
void Enemy::takeDamage(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
		this->setDead();
}

void Enemy::setDead()
{
	this->hp = 0;
}

const std::string Enemy::toStringStats()
{
	std::stringstream ss;

	ss << " Level: " << this->level << "\n"
		<< "\n"

		<< " HP: " << this->hp << " / " << this->hpMax << "\n"
		<< "\n"

		<< " Damage: " << this->damageMin << " - " << this->damageMax << "\n"
		<< " Defence: " << this->defence << "\n"
		<< " Hit rating: " << this->hitRating << "\n"
		<< " Crit chance: " << this->critChance << "\n"
		<< "\n";

	return ss.str();
}
