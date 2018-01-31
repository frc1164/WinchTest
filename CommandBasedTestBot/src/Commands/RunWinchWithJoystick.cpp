#include "RunWinchWithJoystick.h"
#include "../Subsystems/Winch.h"
#include "../RobotMap.h"

RunWinchWithJoystick::RunWinchWithJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(&TestBotWinch);
}

// Called just before this Command runs the first time
void RunWinchWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunWinchWithJoystick::Execute() {
	TestBotWinch.DriveWinch();
}

// Make this return true when this Command no longer needs to run execute()
bool RunWinchWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunWinchWithJoystick::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunWinchWithJoystick::Interrupted() {

}
