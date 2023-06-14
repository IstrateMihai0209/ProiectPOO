#include "StateMachine.h"

void StateMachine::SetState(State* _state)
{
	state = _state;
	state->Start();
}
