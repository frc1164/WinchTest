#ifndef RunWinchWithJoystick_H
#define RunWinchWithJoystick_H

#include "Commands/Command.h"

class RunWinchWithJoystick : public Command {
public:
	RunWinchWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunWinchWithJoystick_H
