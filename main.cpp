#include "./units/Headers/Gameplay/Game.h"

//Global scope
void printMenu()
{
	std::cout << "--- Main Menu ---" << std::endl;
	std::cout << "--- (0) Quit ---" << std::endl;
}

//Main function
int main()
{
	Game game;

	//Game loop
	while (!game.getQuit())
	{
		game.update();
	}

	system("PAUSE");

	return 0; //Exit program
}
