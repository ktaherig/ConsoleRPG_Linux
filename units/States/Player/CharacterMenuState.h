#ifndef CHARACTER_MENU_STATE_H_
#define CHARACTER_MENU_STATE_H_

#include <iostream>
#include <iomanip>
#include <stack>
#include "../../Headers/Player/Character.h"
#include "./CharacterStatMenuState.h"
#include "./CharacterInventoryState.h"

using namespace std;

class CharacterMenuState :
	public State
{
private:
	Character *& character;
	std::stack<State*>*states;

public:
	CharacterMenuState(Character*& character,
		std::stack<State*>* states);
	virtual ~CharacterMenuState();

	//Functions
	void printMenu();
	void updateMenu();
	void update();
};

#endif
