#include "StartMenu.h"

StartMenu::StartMenu(StateManager* _stateManager)
{
	stateManager = _stateManager;
}

void StartMenu::Start()
{
	cout << "Welcome to Airplanes!" << endl;
	this_thread::sleep_for(chrono::seconds(3));
	system("clear");
	Execute();
}

void StartMenu::Execute()
{
	char option;
	bool validOption;
	cout << "1. New Game" << endl;
	cout << "2. Quit Game" << endl;
	do
	{
		cin >> option;
		validOption = true;
		switch (option)
		{
		case '1':
		{
			AirplanePlacing airplanePlacingState(stateManager);
			stateManager->SetState(&airplanePlacingState);
			break;
		}

		case '2':
		{
			exit(0);
			break;
		}
		default:
			validOption = false;
			break;
		}
	} while (!validOption);
}
