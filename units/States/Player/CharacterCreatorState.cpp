#include "./CharacterCreatorState.h"

CharacterCreatorState::CharacterCreatorState(
	std::vector<Character*>* characterList,
	unsigned& activeCharacter,
	std::stack<State*>* states)
	: State(), activeCharacter(activeCharacter), maxCharacters(5)
{
	this->characterList = characterList;
	this->states = states;
}

CharacterCreatorState::~CharacterCreatorState()
{

}

//Functions
void CharacterCreatorState::createCharacter()
{
	if (this->characterList->size() < this->maxCharacters)
	{
		std::string name = "";
		std::string bio = "";

		std::cout << " Name: ";
		std::getline(cin, name);

		std::cout << " Biography: ";
		std::getline(cin, bio);

		this->characterList->push_back(new Character(name, bio));

		std::cout << " Character " << name << " created." << "\n" << "\n";
	}
	else
	{
		std::cout << " Max number of characters reached!" << "\n";
	}
}

/* The original ((for reference))
void CharacterCreatorState::printMenu()
{
	std::system("CLS");
	std::cout << " --- Character Creator ---" << "\n" << "\n"
		<< " Characters: " << to_string(this->characterList->size()) << " / " << to_string(this->maxCharacters) << "\n" << "\n"
		<< " (-1) Back to menu" << "\n"
		<< " (1) New Character" << "\n" << "\n";
}
*/

void CharacterCreatorState::printMenu()
{
	std::stringstream ss;
	ss << " --- Character Creator ---" << "\n" << "\n"
		<< " Characters: " << this->characterList->size() << " / " << this->maxCharacters << "\n" << "\n"
		<< " (-1) Back to menu" << "\n"
		<< " (1) New Character" << "\n" << "\n";
}

void CharacterCreatorState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	case 1:
		std::system("CLS");
		this->createCharacter();
		std::system("PAUSE");
		break;
	default:
		std::system("CLS");
		std::cout << "Not a valid option! " << "\n";
		std::system("PAUSE");
		break;
	}
}

void CharacterCreatorState::update()
{
	this->printMenu();
	this->updateMenu();
}
