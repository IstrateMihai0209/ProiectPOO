#ifndef STARTMENU_H
#define STARTMENU_H
#include "State.h"
#include "StateManager.h"
#include "AirplanePlacing.h"

class StartMenu : public State
{
private:
	StateManager* stateManager;
public:
	StartMenu(StateManager* _stateManager);
	void Start() override;
	void Execute() override;
};

#endif
