#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "StateMachine.h"
#include "Board.h"
#include "AirplanePlacer.h"
#include "Game.h"

class StateManager : public StateMachine
{
public:
	StateManager(AirplanePlacer* _airplanePlacer, Board* _playerboard, Board* _enemyBoard, Board* _opponentBoard, Game* _game);
	AirplanePlacer* airplanePlacer;
	Board* PlayerBoard;
	Board* ComputerBoard;
	Board* OpponentBoard;
	Game* game;
	int NumOfAirplanes = 3;
};

#endif
