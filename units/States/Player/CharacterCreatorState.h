#ifndef CHARACTER_CREATOR_STATE_H_
#define CHARACTER_CREATOR_STATE_H_

#include <iostream>
#include <iomanip>
#include <stack>
#include "../../Headers/Player/Character.h"
#include "../State.h"

using namespace std;

class CharacterCreatorState :
	public State
{
private:
	const unsigned maxCharacters;
	std::vector<Character*>* characterList;
	unsigned& activeCharacter;
	std::stack<State*>*states;

public:
	CharacterCreatorState(
		std::vector<Character*>* characterList,
		unsigned& activeCharacter,
		std::stack<State*>* states);
	virtual ~CharacterCreatorState();

	//Functions
	void createCharacter();
	void printMenu();
	void updateMenu();
	void update();
};

#endif
