#ifndef CHARACTER_SELECTOR_STATE_H_
#define CHARACTER_SELECTOR_STATE_H_

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>

#include "../../Headers/Player/Character.h"
#include "../State.h"

class CharacterSelectorState :
	public State
{
private:
	std::vector<Character*>* characterList;
	unsigned& activeCharacter;
	std::stack<State*>* states;

public:
	CharacterSelectorState(
		std::vector<Character*>* characterList,
		unsigned& activeCharacter,
		std::stack<State*>* states);

	virtual ~CharacterSelectorState();

	//Functions

	void printMenu();
	void updateMenu();
	void update();
};

#endif
