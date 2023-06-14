#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "State.h"

class StateMachine
{
protected:
	State* state;
public:
	void SetState(State* _state);
};

#endif
