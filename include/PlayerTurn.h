#ifndef PLAYERTURN_H
#define PLAYERTURN_H
#include "State.h"
#include "StateManager.h"

class PlayerTurn : public State
{
private:
	StateManager* stateManager;
	bool exitFlag = false;
public:
	PlayerTurn(StateManager* _stateManager);
	void Start() override;
	void Execute() override;
};

#endif
