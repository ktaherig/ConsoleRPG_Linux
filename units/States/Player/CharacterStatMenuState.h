#ifndef CHARACTER_STAT_MENU_STATE_H_
#define CHARACTER_STAT_MENU_STATE_H_

#include <iostream>
#include <iomanip>
#include <stack>
#include "../../Headers/Player/Character.h"
#include "../State.h"

using namespace std;

class CharacterStatMenuState :
	public State
{
private:
	Character *&character;
	std::stack<State*> *states;

public:
	CharacterStatMenuState(
		Character*& character,
		std::stack<State*>* states);
	virtual ~CharacterStatMenuState();

	//Functions
	void printMenu();
	void updateMenu();
	void update();
};

#endif
