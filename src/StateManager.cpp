#include "StateManager.h"

StateManager::StateManager(AirplanePlacer* _airplanePlacer, Board* _playerBoard, Board* _enemyBoard, Board* _opponentBoard, Game* _game)
{
	airplanePlacer = _airplanePlacer;
	PlayerBoard = _playerBoard;
	ComputerBoard = _enemyBoard;
	OpponentBoard = _opponentBoard;
	game = _game;
}
