#include "EndGame.h"
#include "StartMenu.h"

EndGame::EndGame(StateManager* _stateManager)
{
	stateManager = _stateManager;
}

void EndGame::Start()
{
    system("clear");
	cout << "Game over!";
	this_thread::sleep_for(chrono::seconds(5));

	StartMenu startMenuState(stateManager);
	stateManager->SetState(&startMenuState);
}

void EndGame::Execute()
{
}
