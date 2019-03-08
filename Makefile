./main: ./main.o ./Game.o ./Puzzle.o ./Character.o ./Enemy.o ./Inventory.o ./Item.o ./Weapon.o ./Armor.o ./msg_functions.o ./State.o ./CombatState.o ./GameState.o ./MainMenuState.o ./TravelMenuState.o ./CharacterCreatorState.o ./CharacterInventoryState.o ./CharacterMenuState.o ./CharacterSelectorState.o ./CharacterStatMenuState.o
	g++ ./main.o ./Game.o ./Puzzle.o ./Character.o ./Enemy.o ./Inventory.o ./Item.o ./Weapon.o ./Armor.o ./msg_functions.o ./State.o ./CombatState.o ./GameState.o ./MainMenuState.o ./TravelMenuState.o ./CharacterCreatorState.o ./CharacterInventoryState.o ./CharacterMenuState.o ./CharacterSelectorState.o ./CharacterStatMenuState.o -o ./main



./main.o: ./main.cpp ./units/Headers/Gameplay/Game.h
	g++ -c ./main.cpp



./Game.o: ./units/Classes/Gameplay/Game.cpp ./units/Headers/Gameplay/Game.h
	g++ -c ./units/Classes/Gameplay/Game.cpp

./Puzzle.o: ./units/Classes/Gameplay/Puzzle.cpp ./units/Headers/Gameplay/Puzzle.h
	g++ -c ./units/Classes/Gameplay/Puzzle.cpp



./Character.o: ./units/Classes/Player/Character.cpp ./units/Headers/Player/Character.h
	g++ -c ./units/Classes/Player/Character.cpp

./Enemy.o: ./units/Classes/Player/Enemy.cpp ./units/Headers/Player/Enemy.h
	g++ -c ./units/Classes/Player/Enemy.cpp



./msg_functions.o: ./units/Messages/msg_functions.cpp ./units/Messages/msg_functions.h 
	g++ -c ./units/Messages/msg_functions.cpp



./Inventory.o: ./units/Classes/Possessions/Inventory.cpp ./units/Headers/Possessions/Inventory.h
	g++ -c ./units/Classes/Possessions/Inventory.cpp

./Item.o: ./units/Classes/Possessions/Item.cpp ./units/Headers/Possessions/Item.h
	g++ -c ./units/Classes/Possessions/Item.cpp

./Weapon.o: ./units/Classes/Possessions/Weapon.cpp ./units/Headers/Possessions/Weapon.h
	g++ -c ./units/Classes/Possessions/Weapon.cpp

./Armor.o: ./units/Classes/Possessions/Armor.cpp ./units/Headers/Possessions/Armor.h
	g++ -c ./units/Classes/Possessions/Armor.cpp



./State.o: ./units/States/State.cpp ./units/States/State.h
	g++ -c ./units/States/State.cpp

./CombatState.o: ./units/States/Gameplay/CombatState.cpp ./units/States/Gameplay/CombatState.h
	g++ -c ./units/States/Gameplay/CombatState.cpp

./GameState.o: ./units/States/Gameplay/GameState.cpp ./units/States/Gameplay/GameState.h
	g++ -c ./units/States/Gameplay/GameState.cpp

./MainMenuState.o: ./units/States/Gameplay/MainMenuState.cpp ./units/States/Gameplay/MainMenuState.h
	g++ -c ./units/States/Gameplay/MainMenuState.cpp

./TravelMenuState.o: ./units/States/Gameplay/TravelMenuState.cpp ./units/States/Gameplay/TravelMenuState.h
	g++ -c ./units/States/Gameplay/TravelMenuState.cpp



./CharacterCreatorState.o: ./units/States/Player/CharacterCreatorState.cpp ./units/States/Player/CharacterCreatorState.h
	g++ -c ./units/States/Player/CharacterCreatorState.cpp

./CharacterInventoryState.o: ./units/States/Player/CharacterInventoryState.cpp ./units/States/Player/CharacterInventoryState.h
	g++ -c ./units/States/Player/CharacterInventoryState.cpp

./CharacterMenuState.o: ./units/States/Player/CharacterMenuState.cpp ./units/States/Player/CharacterMenuState.h
	g++ -c ./units/States/Player/CharacterMenuState.cpp

./CharacterSelectorState.o: ./units/States/Player/CharacterSelectorState.cpp ./units/States/Player/CharacterSelectorState.h
	g++ -c ./units/States/Player/CharacterSelectorState.cpp

./CharacterStatMenuState.o: ./units/States/Player/CharacterStatMenuState.cpp ./units/States/Player/CharacterStatMenuState.h
	g++ -c ./units/States/Player/CharacterStatMenuState.cpp
