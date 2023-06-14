#include "Game.h"

Game::Game() {}

Airplane Game::GetPlayer1Airplane(int _index)
{
	return player1Airplanes[_index];
}

Airplane Game::GetPlayer2Airplane(int _index)
{
	return player2Airplanes[_index];
}

void Game::SetPlayer1Airplane(Airplane _value, int _index)
{
	player1Airplanes[_index] = _value;
}

void Game::SetPlayer2Airplane(Airplane _value, int _index)
{
	player2Airplanes[_index] = _value;
}
