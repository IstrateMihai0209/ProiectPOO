#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <string>

class Airplane
{
private:
	bool isHeadHit;
	std::string positions[8];
	char* headPosition;
public:
	Airplane();
	std::string* GetPositions();
	void SetPositions(char* _headCoordinates, char _direction);
	bool IsDestroyed;
	int NumOfPartsHit = 0;
};

#endif
