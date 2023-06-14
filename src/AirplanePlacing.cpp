#include "AirplanePlacing.h"
#include "PlayerTurn.h"

AirplanePlacing::AirplanePlacing(StateManager* _stateManager)
{
	stateManager = _stateManager;
}

void AirplanePlacing::Start()
{
	system("clear");
	cout << "Place your airplanes on the board:\n" << endl;
	stateManager->PlayerBoard->DrawBoard();
	Execute();
}

void AirplanePlacing::Execute()
{
	PlaceComputerBoard();
	PlacePlayerBoard();
	PlayerTurn playerTurnState(stateManager);
	stateManager->SetState(&playerTurnState);
}

void AirplanePlacing::PlacePlayerBoard()
{
	for (int i = 1; i <= stateManager->NumOfAirplanes; i++)
	{
		do
		{
			char* coordinates = new char[2];
			char direction;
			cout << "Write the desired coordinates of plane " << i << " (the head will be set on the given position) : ";
			cin >> coordinates;

			system("clear");
			stateManager->airplanePlacer->ShowPreview(coordinates[0] - 'A', coordinates[1] - '0' - 1, *stateManager->PlayerBoard);

			cout << "Type in the desired direction of plane " << i << ": ";
			cin >> direction;

			system("clear");
			stateManager->airplanePlacer->RemovePreview(coordinates[0] - 'A', coordinates[1] - '0' - 1, *stateManager->PlayerBoard);
			stateManager->PlayerBoard->DrawBoard();
			if (stateManager->airplanePlacer->PlaceAirplane(coordinates[0], coordinates[1] - '0' - 1, direction, *stateManager->PlayerBoard))
			{
				system("clear");
				stateManager->PlayerBoard->DrawBoard();
				cout << "Airplane placed succesfully!" << endl;

				Airplane newAirplane;
				newAirplane.SetPositions(coordinates, direction);
				stateManager->game->SetPlayer1Airplane(newAirplane, i);
			}
			this_thread::sleep_for(chrono::seconds(2));
		} while (!stateManager->airplanePlacer->hasBeenPlaced);
		stateManager->airplanePlacer->hasBeenPlaced = false;
	}

}

void AirplanePlacing::PlaceComputerBoard()
{
	for (int i = 1; i <= stateManager->NumOfAirplanes; i++)
	{
		do
		{
			char* coordinates = new char[2];
			char directions[] = {'U', 'R', 'D', 'L'};
			coordinates[0] = 'A' + rand() % 8;
			coordinates[1] = '1' + rand() % 8;
			char airplaneDirection = directions[rand() % 4];
			if (stateManager->airplanePlacer->PlaceAirplane(coordinates[0], coordinates[1] - '0' - 1,
				airplaneDirection, *stateManager->ComputerBoard, true))
			{
				Airplane newAirplane;
				newAirplane.SetPositions(coordinates, airplaneDirection);
				stateManager->game->SetPlayer2Airplane(newAirplane, i);
			}

		} while (!stateManager->airplanePlacer->hasBeenPlaced);
	}
}
