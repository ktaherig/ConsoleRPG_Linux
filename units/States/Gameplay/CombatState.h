#ifndef COMBAT_STATE_H_
#define COMBAT_STATE_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "../State.h"
#include "../../Headers/Player/Character.h"
#include "../../Headers/Player/Enemy.h"

class CombatState :
	public State
{
private:
	Character * & character;
	stack<State*>*states;

public:
	CombatState(Character*& character,
		stack<State*>*states);
	virtual ~CombatState();

	//Functions
	void beginCombat();
	void printMenu();
	void updateMenu();
	void update();
};

#endif
