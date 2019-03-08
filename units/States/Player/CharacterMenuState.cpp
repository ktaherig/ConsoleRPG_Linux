#include "./CharacterMenuState.h"

CharacterMenuState::CharacterMenuState(
	Character*& character,
	std::stack<State*>* states)
	: character(character), State()
{
	this->states = states;
}

CharacterMenuState::~CharacterMenuState()
{

}

//Functions
void CharacterMenuState::printMenu()
{
	std::system("CLS");
	std::cout << gui::msg_menutitle("Character Menu");

	std::cout << this->character->getMenuBar();

	std::cout
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Back to menu.")
		<< gui::msg_menuitem(1, "Name & Bio.")
		<< gui::msg_menuitem(2, "Stats.")
		<< gui::msg_menuitem(3, "Assign statpoints.")
		<< gui::msg_menuitem(4, "Inventory.")
		<< gui::msg_menudivider(40, '-');
}

void CharacterMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	case 1:
		std::system("CLS");
		std::cout << this->character->toStringNameBio() << "\n";
		std::system("PAUSE");
		break;
	case 2:
		std::system("CLS");
		std::cout << this->character->toStringShort() << "\n";
		std::system("PAUSE");
		break;
	case 3:
		this->states->push(new CharacterStatMenuState(this->character, this->states));
		break;
	case 4:
		this->states->push(new CharacterInventoryState(this->character, this->states));
		break;
	default:
		std::system("CLS");
		std::cout << gui::msg_error("Not a valid option.");
		std::system("PAUSE");
		break;
	}
}

void CharacterMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}
