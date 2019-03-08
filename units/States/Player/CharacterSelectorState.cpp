#include "./CharacterSelectorState.h"

CharacterSelectorState::CharacterSelectorState(
	std::vector<Character*>* characterList,
	unsigned& activeCharacter,
	std::stack<State*>* states)
	: State(), 
	characterList(characterList), 
	activeCharacter(activeCharacter), 
	states(states)
{

}

CharacterSelectorState::~CharacterSelectorState()
{

}

//Functions
void CharacterSelectorState::printMenu()
{
	std::system("CLS");
	std::cout << " --- Character Selector ---" << "\n" << "\n";
	
	std::cout << " (-1) Back to menu" << "\n";

	if (!this->characterList->empty())
	{
		for (size_t i = 0; i < this->characterList->size(); i++)
		{
			std::cout << " (" << i << ") " << this->characterList->at(i)->getMenuBar() << "\n";
		}
		std::cout << "\n";
	}
}

void CharacterSelectorState::updateMenu()
{
	if (!this->characterList->empty())
	{
		int choice = this->getChoice();

		if (choice < 0)
		{
			this->setQuit(true);
		}
		else if (choice >= 0 && choice < this->characterList->size())
		{
			this->activeCharacter = choice;
			this->setQuit(true);
			std::cout << " Character " << choice << " selected." << "\n" << "\n";
			std::system("pause");
		}
		else
		{
			std::cout << " Error: Choice out of bounds! " << "\n" << "\n";
			std::system("pause");
		}
	}
	else
	{
		this->setQuit(true);
		std::cout << " No characters created!" << "\n" << "\n";
		std::system("pause");
	}
}

void CharacterSelectorState::update()
{
	this->printMenu();
	this->updateMenu();
}
