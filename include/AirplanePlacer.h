#ifndef AIRPLANEPLACER_H
#define AIRPLANEPLACER_H
#include "Board.h"

class AirplanePlacer
{
private:
	//const int airplaneSize = 8;
	const char kPlanePart = '=';
	const char kEmptySpace = '.';
	char positionsDataSaver[4];
	bool IsAirplanePlacementValid(int _xCoord, int _yCoord, char _direction, Board& _board);
public:
	AirplanePlacer();
	bool hasBeenPlaced;
	bool PlaceAirplane(char _xCoord, int _yCoord, char _direction, Board& _board, bool _isComputer = false);
	void ShowPreview(int _headXCoord, int _headYCoord, Board& _board);
	void RemovePreview(int _headXCoord, int _headYCoord, Board& _board);
};

#endif
