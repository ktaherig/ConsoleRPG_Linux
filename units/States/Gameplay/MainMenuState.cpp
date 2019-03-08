#include "./MainMenuState.h"

MainMenuState::MainMenuState(
		std::vector<Character*>* characterList,
		unsigned& activeCharacter,
		std::stack<State*>* states)
	: State(), activeCharacter(activeCharacter)
{
	this->characterList = characterList;
	this->states = states;

	//FOR DEVELOPMENT PURPOSES
	this->characterList->push_back(new Character("TEST", "DEBUGGING CHARACTER"));
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::printMenu()
{
	std::system("CLS");
	std::cout << gui::msg_menutitle("\n\n\n\n\nMain Menu");

	if (!this->characterList->empty())
		std::cout << this->characterList->at(this->activeCharacter)->getMenuBar();
	else
		std::cout << gui::msg_error("No character selected.");

	std::cout 
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Quit to desktop. ")
		<< gui::msg_menuitem(1, "Start game. ")
		<< gui::msg_menuitem(2, "Create character. ")
		<< gui::msg_menuitem(3, "Select character. ")
		<< gui::msg_menudivider(40, '-');
}

void MainMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	case 1:
		if (!this->characterList->empty())
			this->states->push(new GameState(this->characterList->at(this->activeCharacter), this->states));
		else
		{
			std::system("CLS");
			std::cout << "  [[ (!) Error. Create a character first. ]]" << "\n";
			std::system("PAUSE");
		}
		break;
	case 2:
		this->states->push(new CharacterCreatorState(this->characterList, this->activeCharacter, this->states));
		break;
	case 3:
		this->states->push(new CharacterSelectorState(this->characterList, this->activeCharacter, this->states));
		break;
	default:
		std::system("CLS");
		std::cout << "  [[ (!) Not a valid option. ]]" << "\n";
		std::system("PAUSE");
		break;
	}
}

//Functions
void MainMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}
