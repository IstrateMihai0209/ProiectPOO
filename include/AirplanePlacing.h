#ifndef AIRPLANEPLACING_H
#define AIRPLANEPLACING_H
#include "State.h"
#include "StateManager.h"

class AirplanePlacing : public State
{
private:
	StateManager* stateManager;
	void PlacePlayerBoard();
	void PlaceComputerBoard();
public:
	//AirplanePlacing(StateManager* stateManager) : State(stateManager) { }
	AirplanePlacing(StateManager* _stateManager);
	void Start() override;
	void Execute() override;
};

#endif
