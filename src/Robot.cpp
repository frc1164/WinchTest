/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <Joystick.h>
#include <Victor.h>

//Victor 7 is inverted

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

		Stick = new Joystick(0);
		Winch1 = new Victor(1); // good
		Winch2 = new Victor(2); // good
		Winch3 = new Victor(3); // good
		Winch4 = new Victor(5); // good
		Winch5 = new Victor(6); // good
		Winch6 = new Victor(7); // good

		Winch1->SetInverted(true);
		Winch2->SetInverted(true);
		Winch6->SetInverted(true);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 */
	void AutonomousInit() override {
		m_autoSelected = m_chooser.GetSelected();
		// m_autoSelected = SmartDashboard::GetString(
		// 		"Auto Selector", kAutoNameDefault);
		std::cout << "Auto selected: " << m_autoSelected << std::endl;

		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() {
	}

	void TeleopPeriodic() {
		if (IsEnabled()){
			RightStick = Stick->GetRawAxis(2);

			if (Stick->GetRawButton(2) == 1){
				Winch1->Set(1);
				Winch2->Set(1);
				Winch3->Set(1);
				Winch4->Set(1);
				Winch5->Set(1);
				Winch6->Set(1);
			}

			else{
				Winch1->Set(RightStick);
				Winch2->Set(RightStick);
				Winch3->Set(RightStick);
				Winch4->Set(RightStick);
				Winch5->Set(RightStick);
				Winch6->Set(RightStick);
			}

		}
	}

	void TestPeriodic() {}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
	Joystick *Stick;
	Victor *Winch1, *Winch2, *Winch3, *Winch4, *Winch5, *Winch6;
	double RightStick;
};

START_ROBOT_CLASS(Robot)
