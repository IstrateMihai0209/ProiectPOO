#include "AirplanePlacer.h"

AirplanePlacer::AirplanePlacer()
{
}

bool AirplanePlacer::PlaceAirplane(char _xCoord, int _yCoord, char _direction, Board& _board, bool _isComputer)
{
	int xIndex = _xCoord - 'A';
	int yIndex = _yCoord;

	hasBeenPlaced = IsAirplanePlacementValid(xIndex, yIndex, _direction, _board);
	if (!hasBeenPlaced)
	{
		if (_isComputer) return false;

		cout << "Invalid airplane placement!" << endl;
		return false;
	}

	if (_direction == 'D')
	{
		_board.SetCell(xIndex, yIndex, '^');
		_board.SetCell(xIndex + 1, yIndex, kPlanePart);
		_board.SetCell(xIndex + 1, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex + 1, yIndex + 1, kPlanePart);
		_board.SetCell(xIndex + 2, yIndex, kPlanePart);
		_board.SetCell(xIndex + 3, yIndex, kPlanePart);
		_board.SetCell(xIndex + 3, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex + 3, yIndex + 1, kPlanePart);
	}
	if (_direction == 'L')
	{
		_board.SetCell(xIndex, yIndex, '>');
		_board.SetCell(xIndex, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex - 1, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex + 1, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex, yIndex - 2, kPlanePart);
		_board.SetCell(xIndex, yIndex - 3, kPlanePart);
		_board.SetCell(xIndex - 1, yIndex - 3, kPlanePart);
		_board.SetCell(xIndex + 1, yIndex - 3, kPlanePart);
	}
	if (_direction == 'U')
	{
		_board.SetCell(xIndex, yIndex, 'v');
		_board.SetCell(xIndex - 1, yIndex, kPlanePart);
		_board.SetCell(xIndex - 1, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex - 1, yIndex + 1, kPlanePart);
		_board.SetCell(xIndex - 2, yIndex, kPlanePart);
		_board.SetCell(xIndex - 3, yIndex, kPlanePart);
		_board.SetCell(xIndex - 3, yIndex - 1, kPlanePart);
		_board.SetCell(xIndex - 3, yIndex + 1, kPlanePart);
	}
	if (_direction == 'R')
	{
		_board.SetCell(xIndex, yIndex, '<');
		_board.SetCell(xIndex, yIndex + 1, kPlanePart);
		_board.SetCell(xIndex - 1, yIndex + 1, kPlanePart);
		_board.SetCell(xIndex + 1, yIndex + 1, kPlanePart);
		_board.SetCell(xIndex, yIndex + 2, kPlanePart);
		_board.SetCell(xIndex, yIndex + 3, kPlanePart);
		_board.SetCell(xIndex - 1, yIndex + 3, kPlanePart);
		_board.SetCell(xIndex + 1, yIndex + 3, kPlanePart);
	}

	return true;
}

void AirplanePlacer::ShowPreview(int _headXCoord, int _headYCoord, Board& _board)
{
	positionsDataSaver[0] = _board.GetCell(_headXCoord - 1, _headYCoord);
	positionsDataSaver[1] = _board.GetCell(_headXCoord + 1, _headYCoord);
	positionsDataSaver[2] = _board.GetCell(_headXCoord, _headYCoord - 1);
	positionsDataSaver[3] = _board.GetCell(_headXCoord, _headYCoord + 1);

	_board.SetCell(_headXCoord - 1, _headYCoord, 'U');
	_board.SetCell(_headXCoord + 1, _headYCoord, 'D');
	_board.SetCell(_headXCoord, _headYCoord - 1, 'L');
	_board.SetCell(_headXCoord, _headYCoord + 1, 'R');
	_board.DrawBoard();
}

void AirplanePlacer::RemovePreview(int _headXCoord, int _headYCoord, Board& _board)
{
	_board.SetCell(_headXCoord - 1, _headYCoord, positionsDataSaver[0]);
	_board.SetCell(_headXCoord + 1, _headYCoord, positionsDataSaver[1]);
	_board.SetCell(_headXCoord, _headYCoord - 1, positionsDataSaver[2]);
	_board.SetCell(_headXCoord, _headYCoord + 1, positionsDataSaver[3]);
}

bool AirplanePlacer::IsAirplanePlacementValid(int _xCoord, int _yCoord, char _direction, Board& _board)
{
	if (_board.GetCell(_xCoord, _yCoord) != kEmptySpace) return false;
	if (_direction == 'D')
	{
		if (_xCoord + 3 >= _board.GetBoardSize()) return false;
		if (_yCoord + 2 > _board.GetBoardSize() || _yCoord - 1 < 0) return false;

		if (_board.GetCell(_xCoord + 1, _yCoord) != kEmptySpace ||
			_board.GetCell(_xCoord + 1, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord + 1, _yCoord + 1) != kEmptySpace ||
			_board.GetCell(_xCoord + 2, _yCoord) != kEmptySpace ||
			_board.GetCell(_xCoord + 3, _yCoord) != kEmptySpace ||
			_board.GetCell(_xCoord + 3, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord + 3, _yCoord + 1) != kEmptySpace)
			return false;
	}
	if (_direction == 'L')
	{
		if (_xCoord + 2 > _board.GetBoardSize() || _xCoord - 1 < 0) return false;
		if (_yCoord - 3 < 0) return false;

		if (_board.GetCell(_xCoord, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord - 1, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord + 1, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord, _yCoord - 2) != kEmptySpace ||
			_board.GetCell(_xCoord, _yCoord - 3) != kEmptySpace ||
			_board.GetCell(_xCoord - 1, _yCoord - 3) != kEmptySpace ||
			_board.GetCell(_xCoord + 1, _yCoord - 3) != kEmptySpace)
			return false;
	}
	if (_direction == 'U')
	{
		if (_xCoord - 3 < 0) return false;
		if (_yCoord - 1 < 0 || _yCoord + 2 > _board.GetBoardSize()) return false;

		if(_board.GetCell(_xCoord - 1, _yCoord) != kEmptySpace ||
			_board.GetCell(_xCoord - 1, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord - 1, _yCoord + 1) != kEmptySpace ||
			_board.GetCell(_xCoord - 2, _yCoord) != kEmptySpace ||
			_board.GetCell(_xCoord - 3, _yCoord) != kEmptySpace ||
			_board.GetCell(_xCoord - 3, _yCoord - 1) != kEmptySpace ||
			_board.GetCell(_xCoord - 3, _yCoord + 1) != kEmptySpace)
			return false;
	}
	if (_direction == 'R')
	{
		if (_xCoord + 2 > _board.GetBoardSize() || _xCoord - 1 < 0) return false;
		if (_yCoord + 3 >= _board.GetBoardSize()) return false;

		if(_board.GetCell(_xCoord, _yCoord + 1) != kEmptySpace ||
			_board.GetCell(_xCoord - 1, _yCoord + 1) != kEmptySpace ||
			_board.GetCell(_xCoord + 1, _yCoord + 1) != kEmptySpace ||
			_board.GetCell(_xCoord, _yCoord + 2) != kEmptySpace ||
			_board.GetCell(_xCoord, _yCoord + 3) != kEmptySpace ||
			_board.GetCell(_xCoord - 1, _yCoord + 3) != kEmptySpace ||
			_board.GetCell(_xCoord + 1, _yCoord + 3) != kEmptySpace)
			return false;
	}

	return true;
}
