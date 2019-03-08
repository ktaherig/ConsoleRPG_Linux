#ifndef GAME_H_
#define GAME_H_

#include "../../States/Gameplay/MainMenuState.h"
#include "../../States/State.h"

//using namespace std;

class Game
{
private:
	//Variables
	bool quit;
	
	unsigned activeCharacter;
	std::vector<Character*> characterList;
	std::stack<State*> states;

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool& getQuit() const;

	//Modifiers

	//Functions
	// int getChoice(); // this is contained in State.h
	// void printMenu(); // this is contained in MainMenuState.h
	void update();
};

#endif /* ifndef GAME_H_ */
