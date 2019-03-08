#ifndef GAME_STATE_H_
#define GAME_STATE_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "../State.h"
#include "../../Headers/Player/Character.h"
#include "../../Headers/Player/Enemy.h"
#include "../Player/CharacterMenuState.h"
#include "../Gameplay/TravelMenuState.h"

using namespace std;

class GameState :
	public State
{
private:
	Character *& character;
	stack<State*>*states;

public:
	GameState(Character*& character, stack<State*>*states);
	virtual ~GameState();

	//Functions
	void printMenu() const;
	void updateMenu();
	void update();
};

#endif
