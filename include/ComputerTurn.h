#ifndef COMPUTERTURN_H
#define COMPUTERTURN_H
#include "State.h"
#include "StateManager.h"

class ComputerTurn : public State
{
private:
	StateManager* stateManager;
	bool exitFlag = false;
public:
	ComputerTurn(StateManager* _stateManager);
	void Start() override;
	void Execute() override;
};

#endif
