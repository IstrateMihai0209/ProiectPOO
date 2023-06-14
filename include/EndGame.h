#ifndef ENDGAME_H
#define ENDGAME_H
#include "State.h"
#include "StateManager.h"

class EndGame : public State
{
private:
	StateManager* stateManager;
public:
	EndGame(StateManager* _stateManager);
	void Start() override;
	void Execute() override;
};

#endif
