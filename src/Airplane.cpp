#include "Airplane.h"

Airplane::Airplane() {}

std::string* Airplane::GetPositions()
{
	return positions;
}

void Airplane::SetPositions(char* _headPosition, char _direction)
{
	positions[0] = std::string(1, _headPosition[0]) + _headPosition[1];
	switch(_direction)
	{
	case 'U':
		positions[1] = std::string(1, _headPosition[0] - 1) + _headPosition[1];
		positions[2] = std::string(1, _headPosition[0] - 1) + std::string(1, _headPosition[1] - 1);
		positions[3] = std::string(1, _headPosition[0] - 1) + std::string(1, _headPosition[1] + 1);
		positions[4] = std::string(1, _headPosition[0] - 2) + _headPosition[1];
		positions[5] = std::string(1, _headPosition[0] - 3) + _headPosition[1];
		positions[6] = std::string(1, _headPosition[0] - 3) + std::string(1, _headPosition[1] - 1);
		positions[7] = std::string(1, _headPosition[0] - 3) + std::string(1, _headPosition[1] + 1);
		break;
	case 'R':
		positions[1] = std::string(1, _headPosition[0]) + std::string(1, _headPosition[1] + 1);
		positions[2] = std::string(1, _headPosition[0] - 1) + std::string(1, _headPosition[1] + 1);
		positions[3] = std::string(1, _headPosition[0] + 1) + std::string(1, _headPosition[1] + 1);
		positions[4] = std::string(1, _headPosition[0]) + std::string(1, _headPosition[1] + 2);
		positions[5] = std::string(1, _headPosition[0]) + std::string(1, _headPosition[1] + 3);
		positions[6] = std::string(1, _headPosition[0] - 1) + std::string(1, _headPosition[1] + 3);
		positions[7] = std::string(1, _headPosition[0] + 1) + std::string(1, _headPosition[1] + 3);
		break;
	case 'D':
		positions[1] = std::string(1, _headPosition[0] + 1) + _headPosition[1];
		positions[2] = std::string(1, _headPosition[0] + 1) + std::string(1, _headPosition[1] - 1);
		positions[3] = std::string(1, _headPosition[0] + 1) + std::string(1, _headPosition[1] + 1);
		positions[4] = std::string(1, _headPosition[0] + 2) + _headPosition[1];
		positions[5] = std::string(1, _headPosition[0] + 3) + _headPosition[1];
		positions[6] = std::string(1, _headPosition[0] + 3) + std::string(1, _headPosition[1] - 1);
		positions[7] = std::string(1, _headPosition[0] + 3) + std::string(1, _headPosition[1] + 1);
		break;
	case 'L':
		positions[1] = std::string(1, _headPosition[0]) + std::string(1, _headPosition[1] - 1);
		positions[2] = std::string(1, _headPosition[0] - 1) + std::string(1, _headPosition[1] - 1);
		positions[3] = std::string(1, _headPosition[0] + 1) + std::string(1, _headPosition[1] - 1);
		positions[4] = std::string(1, _headPosition[0]) + std::string(1, _headPosition[1] - 2);
		positions[5] = std::string(1, _headPosition[0]) + std::string(1, _headPosition[1] - 3);
		positions[6] = std::string(1, _headPosition[0] - 1) + std::string(1, _headPosition[1] - 3);
		positions[7] = std::string(1, _headPosition[0] + 1) + std::string(1, _headPosition[1] - 3);
		break;
	}
}
