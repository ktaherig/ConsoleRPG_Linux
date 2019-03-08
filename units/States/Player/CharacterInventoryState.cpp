#include "./CharacterInventoryState.h"

CharacterInventoryState::CharacterInventoryState(
Character*& character,
std::stack<State*>*states)
	: State(), character(character)
{
	this->states = states;
}

CharacterInventoryState::~CharacterInventoryState()
{

}

void CharacterInventoryState::printMenu() const
{
	std::system("CLS");
	std::cout << gui::msg_menutitle("Inventory Menu");

	std::cout
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Quit to menu.")
		<< gui::msg_menuitem(1, "Show inventory.")
		<< gui::msg_menuitem(2, "Equip item.")
		<< gui::msg_menuitem(3, "Destroy item.")
		<< gui::msg_menudivider(40, '-');
}

void CharacterInventoryState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;

	case 1:
		std::system("CLS");
		std::cout << this->character->getInventory().toString() << "\n";
		std::system("PAUSE");
		break;

	case 2:
	{
		std::system("CLS");
		std::cout << this->character->getInventory().toString() << "\n";

		int choice = this->getChoice();

		if (choice < 0 || choice >= this->character->getInventory().size())
			std::cout << gui::msg_error("No such item in inventory.");
		else
		{
			Weapon* weapon_ptr = dynamic_cast<Weapon*>(&this->character->getInventory().at(choice));
			Armor* armor_ptr = dynamic_cast<Armor*>(&this->character->getInventory().at(choice));
			
			if (weapon_ptr)
			{
				weapon_ptr = static_cast<Weapon*>(this->character->getInventory().replace(choice, this->character->getWeapon()));
				this->character->setWeapon(weapon_ptr);

				std::cout << gui::msg_alert(weapon_ptr->getName() + " equipped.");
				std::system("pause");
			}
			else if (armor_ptr)
			{
				armor_ptr = static_cast<Armor*>(this->character->getInventory().replace(choice, this->character->getArmor(armor_ptr->getArmorType())));
				this->character->setArmor(armor_ptr, armor_ptr->getArmorType());

				std::cout << gui::msg_alert(armor_ptr->getName() + " equipped.");
				std::system("pause");
			}
		}

		break;
	}
	default:
		std::system("CLS");
		std::cout << "Not a valid option!" << "\n";
		std::system("PAUSE");
		break;
	}
}

void CharacterInventoryState::update()
{
	//Print the menu
	this->printMenu();

	//Get a choice and choose valid option
	this->updateMenu();
}
