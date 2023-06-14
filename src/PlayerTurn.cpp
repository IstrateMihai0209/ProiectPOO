#include "PlayerTurn.h"
#include "ComputerTurn.h"
#include "EndGame.h"

PlayerTurn::PlayerTurn(StateManager* _stateManager)
{
	stateManager = _stateManager;
}

void PlayerTurn::Start()
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
		ComputerTurn computerTurnState(stateManager);
		stateManager->SetState(&computerTurnState);
	}
	else
	{
		EndGame endGameState(stateManager);
		stateManager->SetState(&endGameState);
	}
}

void PlayerTurn::Execute()
{
	char* coordinates = new char[2];
	bool isValidPosition = false;
	do
	{
		cout << "Type in the position you want to attack on your opponent's board: ";
		cin >> coordinates;
		char hitPosition = stateManager->ComputerBoard->GetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1);

		switch (hitPosition)
		{
			case '.':
				isValidPosition = true;
				stateManager->OpponentBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, '#');
				stateManager->ComputerBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, '#');
				break;
			case '=':
				isValidPosition = true;
				for (int i = 1; i <= 3; i++)
				{
					Airplane opponentAirplane = stateManager->game->GetPlayer2Airplane(i);
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

				stateManager->OpponentBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, 'X');
				stateManager->ComputerBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, 'X');
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
							stateManager->game->Player2PlanesDestroyed++;
							break;
						}
					}
				}

				stateManager->OpponentBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, '*');
				stateManager->ComputerBoard->SetCell(coordinates[0] - 'A', coordinates[1] - '0' - 1, '*');
				break;
			default:
				break;
		}
		if (stateManager->game->Player2PlanesDestroyed == 3)
			exitFlag = true;
	} while (!isValidPosition);
}
