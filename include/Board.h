#include <iostream>
#ifndef BOARD_H
#define BOARD_H
using namespace std;

class Board
{
private:
	int BoardSize = 8;
	const char kEmptySpace = '.';
	const char kPlanePart = '=';
	const char kPlaneHit = 'X';
	const char kMiss = '#';
	char** board = new char*[BoardSize];
public:
	Board();
	~Board();
	char GetCell(int _xCoord, int _yCoord);
	void SetCell(int _xCoord, int _yCoord, char _value);
	int GetBoardSize();
	void DrawBoard();
};

#endif
