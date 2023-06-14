#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class State
{
public:
	virtual void Start() = 0;
	virtual void Execute() = 0;
};

#endif
