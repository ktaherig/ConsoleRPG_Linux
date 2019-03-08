#include "./CombatState.h"

CombatState::CombatState(
	Character*& character,
	stack<State*>* states)
	: character(character), State()

{
	this->states = states;
}

CombatState::~CombatState()
{

}

//functions
void CombatState::beginCombat()
{
	Enemy enemy(this->character->getLevel(), rand() % 100);
	bool endCombat = false;

	int turn = rand() % 2;
	int round = 0;

	srand(time(NULL));

	while (!endCombat)
	{
		//Test for player attacking and enemy defending
		std::string atkStr = "Player";
		std::string defStr = "Enemy";
		float hitRating = static_cast<float>(this->character->getHitRating());
		float defence = static_cast<float>(enemy.getDefence());

		if (!turn)
		{
			atkStr = "Enemy";
			defStr = "Player";
			hitRating = static_cast<float>(enemy.getHitRating());
			defence = static_cast<float>(this->character->getDefence());
		}

		float totalHitDef = hitRating + defence;
		float hitPercent = 100.f * (hitRating / totalHitDef);
		float defPercent = 100.f * (defence / totalHitDef);

		int random = rand() % 100 + 1;

		std::system("cls");
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << " Attacker: " << atkStr << "\n";
		std::cout << " Defender: " << defStr << "\n";
		std::cout << " Round: " << ++round << "\n";
		std::cout << "-------------------------------------------------" << "\n";

		//Hit
		if (random > 0 && random <= hitPercent)
		{
			int damage = 0;

			if (turn)
			{
				damage = character->getTotalDamage();
				enemy.takeDamage(damage);
			}
			else
			{
				damage = rand() % (enemy.getDamageMax() - enemy.getDamageMin()) + enemy.getDamageMin();
				this->character->takeDamage(damage);
			}

			std::cout << atkStr << " HIT " << defStr << " FOR " << damage << "!" << "\n";
		}
		//Defend
		else
		{
			std::cout << atkStr << " MISSED " << defStr << "\n";
		}

		//Data
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << " Hit rating: " << hitRating << " Percent: " << hitPercent << "\n";
		std::cout << " Defence: " << defence << " Percent: " << defPercent << "\n";
		std::cout << " Player Damage: " << this->character->getDamageMin() << " - " << this->character->getDamageMax() << "\n";
		std::cout << " Enemy Damage: " << enemy.getDamageMin() << " - " << enemy.getDamageMax() << "\n";
		std::cout << " Player HP: " << this->character->getHP() << " / " << this->character->getHPMax() << "\n";
		std::cout << " Enemy HP: " << enemy.getHP() << " / " << enemy.getHPMax() << "\n";
		std::cout << " Enemy Dropchance: " << enemy.getDropChance() << "\n";
		std::cout << "-------------------------------------------------" << "\n";

		//Loss
		if (this->character->isDead())
		{
			endCombat = true;
			std::cout << "YOU ARE DEAD AND YOU LOST SOME EXP AND GOLD!" << "\n";
			this->setQuit(true);
		}
		//Win
		else if (enemy.isDead())
		{
			// End Combat
			endCombat = true;

			// Gain Experience
			int gainedExp = rand() % (enemy.getLevel() * 20) + (enemy.getLevel() * 10);
			this->character->addExp(gainedExp);

			// Gain Gold
			int gainedGold = rand() % (enemy.getLevel() * 20) + (enemy.getLevel() * 30);
			this->character->addGold(gainedGold);

			// Gain Flask Shard
			int shardDrop = rand() % 100 + 1;
			if (shardDrop <= 3) {
				this->character->addFlaskShard();
				std::cout << gui::msg_alert("Gained a flask shard!") << std::endl;
			}

			// Gain Item 
			int drop = rand() % 100 + 1;

			if (drop <= enemy.getDropChance()) {
				int armor_or_weapon = rand() % 2;
				if (armor_or_weapon) {
					this->character->getInventory().add(Weapon(enemy.getLevel(), rand() % NR_OF_ITEM_RARITIES));
				} else {
					this->character->getInventory().add(Armor(enemy.getLevel(), rand() % NR_OF_ITEM_RARITIES));
				}

				std::cout << gui::msg_alert("Item dropped and added to inventory!") << std::endl;
			}

			// End Text
			std::cout << "You've defeated the enemy and gained "
				<< gainedExp << " experience and "
				<< gainedGold << " gold!\n"
				<< std::endl;

			// End State
			this->setQuit(true);
		}

		//Switch turn
		turn = turn ? false : true;

		std::system("pause");
	}
}

void CombatState::printMenu()
{
	std::system("CLS");
	std::cout << " --- Combat Menu ---" << "\n" << "\n";
	std::cout << this->character->getMenuBar() << "\n" << "\n";
	std::cout << " (1) Begin Combat" << "\n"
		<< " (2) Flee" << "\n"
		<< " (3) Heal" << "\n"
		<< "\n";
}

void CombatState::updateMenu()
{
	switch (this->getChoice())
	{
	case 1:
		this->beginCombat();
		std::cout << "END OF COMBAT." << "\n";
		std::system("pause");
		//this->setQuit(true);
		break;

	case 2:
		std::system("cls");
		std::cout << "You fled and lost some valuables..." << std::endl;
		//gui::msg_alert("You fled and lost some valuables...");
		std::cout << this->character->flee() << "\n";
		std::system("pause");
		this->setQuit(true);
		break;

	case 3:
		std::system("cls");
		if (this->character->consumeFlask())
		{
			std::cout << "Consumed a flask and gained HP!" << std::endl;
			//gui::msg_alert("Consumed a flask and gained HP!");
		} else {
			std::cout << "The flasks are empty" << std::endl;
			//gui::msg_alert("The flasks are empty");
		}
		std::system("pause");
		break;

	default:
		std::system("CLS");
		std::cout << "Not a valid option! " << std::endl;
		//gui::msg_error("Not a valid option! ");
		std::system("PAUSE");
		break;
	}
}

//Functions


void CombatState::update()
{
	this->printMenu();
	this->updateMenu();
}
