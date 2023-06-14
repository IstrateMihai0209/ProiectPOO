#include <iostream>
#include "StateManager.h"
#include "State.h"
#include "StartMenu.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Board playerBoard;
	Board enemyBoard;
	Board opponentBoard;
	AirplanePlacer airplanePlacer;
	Game game;
	StateManager stateManager(&airplanePlacer, &playerBoard, &enemyBoard, &opponentBoard, &game);

	//States
	StartMenu startMenu(&stateManager);

	//Execution
	stateManager.SetState(&startMenu);
}
