#ifndef CHARACTER_INVENTORY_STATE_H_
#define CHARACTER_INVENTORY_STATE_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "../State.h"
#include "../../Headers/Player/Character.h"

using namespace std;

class CharacterInventoryState :
	public State
{
private:
	Character * & character;
	std::stack<State*>*states;

public:
	CharacterInventoryState(Character*& character, std::stack<State*>*states);

	virtual ~CharacterInventoryState();

	//Functions
	void printMenu() const;
	void updateMenu();
	void update();
};

#endif
