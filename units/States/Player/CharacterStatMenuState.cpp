#include "./CharacterStatMenuState.h"

CharacterStatMenuState::CharacterStatMenuState(
Character*& character,
std::stack<State*>* states)
	: character(character), State()

{
	this->states = states;
}


CharacterStatMenuState::~CharacterStatMenuState()
{

}

void CharacterStatMenuState::printMenu()
{
	std::system("CLS");
	std::cout << gui::msg_menutitle("Statpoint Menu");

	std::cout << this->character->getMenuBar(true);

	std::cout << gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Quit to menu")
		<< gui::msg_menuitem(1, "Strength")
		<< gui::msg_menuitem(2, "Vitality")
		<< gui::msg_menuitem(3, "Agility")
		<< gui::msg_menuitem(4, "Dexterity")
		<< gui::msg_menuitem(5, "Intelligence")
		<< gui::msg_menudivider(40, '-');
}

void CharacterStatMenuState::updateMenu()
{
	int choice = this->getChoice();

	if (choice == -1)
	{
		this->setQuit(true);
	}
	else if (choice >= 1 && choice <= 5)
	{
		if (!this->character->addStatpoint(choice - 1))
			cout << gui::msg_error("Not enough statpoints.");
	}
	else
	{
		std::system("CLS");
		std::cout << gui::msg_error("Not a valid option.");
		std::system("PAUSE");
	}
}

//Functions


void CharacterStatMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}
