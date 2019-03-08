#include "../../Headers/Gameplay/Game.h"

//Constructors and Destructors
Game::Game()
{
	srand(time(NULL));

	quit = false;

	this->activeCharacter = 0;
	this->states.push(new MainMenuState(&this->characterList, this->activeCharacter, &this->states));
}

Game::~Game()
{
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

	for (size_t i = 0; i < this->characterList.size(); i++)
	{
		delete this->characterList[i];
	}
}

//Accessor
const bool& Game::getQuit() const
{
	return this->quit;
}

//Modifier
// int Game::getChoice()
// {
	// int choice = 0;
	// return choice;
// }

//Functions
void Game::update()
{
	this->states.top()->update();
	if (this->states.top()->getQuit())
	{
		delete this->states.top();
		this->states.pop();
	}

	if (this->states.empty())
		this->quit = true;
}
