#include "ComputerTurn.h"
#include "PlayerTurn.h"
#include "EndGame.h"

ComputerTurn::ComputerTurn(StateManager* _stateManager)
{
	stateManager = _stateManager;
}

void ComputerTurn::Start()
{
	system("clear");
	cout << "PLAYER BOARD" << endl;
	stateManager->PlayerBoard->DrawBoard();
	cout << "-----------------------------" << endl;
	cout << "OPPONENT BOARD" << endl;
	stateManager->OpponentBoard->DrawBoard();
	Execute();

	if (!exitFlag)
	{
		PlayerTurn playerTurnState(stateManager);
		stateManager->SetState(&playerTurnState);
	}
	else
	{
		EndGame endGameState(stateManager);
		stateManager->SetState(&endGameState);
	}
}

void ComputerTurn::Execute()
{
	cout << "Waiting for opponent to hit...";
	bool isValidPosition = false;
	do
	{
		char* coordinates = new char[2];
		coordinates[0] = 'A' + rand() % 8;
		coordinates[1] = '1' + rand() % 8;
		char hitPosition = stateManager->PlayerBoard->GetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1);
		switch (hitPosition)
		{
			case '.':
				isValidPosition = true;
				stateManager->PlayerBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, '#');
				break;

			case '=':
				isValidPosition = true;
				for (int i = 1; i <= 3; i++)
				{
					Airplane opponentAirplane = stateManager->game->GetPlayer1Airplane(i);
					std::string* planePositions = opponentAirplane.GetPositions();
					for (int j = 0; j < 8; j++)
					{
						if (planePositions[j] == coordinates)
						{
							opponentAirplane.NumOfPartsHit++;
							if (opponentAirplane.NumOfPartsHit == 7)
								opponentAirplane.IsDestroyed = true;
							break;
						}
					}
				}

				stateManager->PlayerBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, 'X');
				break;

			case '^':
			case '>':
			case 'v':
			case '<':
				isValidPosition = true;
				for (int i = 1; i <= 3; i++)
				{
					Airplane opponentAirplane = stateManager->game->GetPlayer2Airplane(i);
					std::string* planePositions = opponentAirplane.GetPositions();
					for (int j = 0; j < 8; j++)
					{
						if (planePositions[j] == coordinates)
						{
							opponentAirplane.IsDestroyed = true;
							stateManager->game->Player1PlanesDestroyed++;
							break;
						}
					}
				}

				stateManager->PlayerBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, '*');
				break;

			default:
				break;
		}
		if (stateManager->game->Player1PlanesDestroyed == 3)
			exitFlag = true;
	} while (!isValidPosition);
	std::this_thread::sleep_for(chrono::seconds(3));
}
