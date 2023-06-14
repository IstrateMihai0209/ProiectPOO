#ifndef GAME_H
#define GAME_H
#include "Airplane.h"
#include <vector>

class Game
{
private:
	Airplane player1Airplanes[4];
	Airplane player2Airplanes[4];
public:
	Game();
	Airplane GetPlayer1Airplane(int _index);
	Airplane GetPlayer2Airplane(int _index);
	void SetPlayer1Airplane(Airplane _value, int _index);
	void SetPlayer2Airplane(Airplane _value, int _index);
	int Player1PlanesDestroyed = 0;
	int Player2PlanesDestroyed = 0;
};

#endif
