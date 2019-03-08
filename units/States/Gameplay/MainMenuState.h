#ifndef MAIN_MENU_STATE_H_
#define MAIN_MENU_STATE_H_

#include <iostream>
#include <iomanip>
#include <stack>
#include "../Player/CharacterCreatorState.h"
#include "../Player/CharacterSelectorState.h"
#include "./GameState.h"

using namespace std;

class MainMenuState
	: public State
{
private:
	std::vector<Character*>* characterList;
	unsigned& activeCharacter;
	std::stack<State*>* states;

public:
	MainMenuState(
		std::vector<Character*>* characterList,
		unsigned& activeCharacter,
		std::stack<State*>* states);
	virtual ~MainMenuState();

	void printMenu();
	//const int getChoice() const;
	void updateMenu();
	void update();
};

#endif
