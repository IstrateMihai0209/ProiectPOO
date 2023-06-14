#include "Board.h"

Board::Board()
{
	for (int i = 0; i < BoardSize; i++)
	{
		board[i] = new char[BoardSize];

		for (int j = 0; j < BoardSize; j++)
		{
			board[i][j] = kEmptySpace;
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < BoardSize; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

int Board::GetBoardSize()
{
	return BoardSize;
}

char Board::GetCell(int _xCoord, int _yCoord)
{
	if (_xCoord < 0 || _yCoord < 0 || _xCoord >= BoardSize || _yCoord >= BoardSize) return NULL;
	return board[_xCoord][_yCoord];
}

void Board::SetCell(int _xCoord, int _yCoord, char _value)
{
	if (_xCoord < 0 || _yCoord < 0 || _xCoord >= BoardSize || _yCoord >= BoardSize) return;
	board[_xCoord][_yCoord] = _value;
}

void Board::DrawBoard()
{
	cout << "  ";
	for (int i = 1; i <= BoardSize; i++)
	{
		cout << i << " ";
	}
	cout << endl;

	for (int i = 0; i < BoardSize; i++)
	{
		cout << char('A' + i) << " ";

		for (int j = 0; j < BoardSize; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
