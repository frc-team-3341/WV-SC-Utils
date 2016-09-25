# WV-SC-Utils
Certain Utilities used by FRC 3341 in Systems Control

##TODO: The wvrobotics Namespace
* TODO: Add wvrobotics.cpp file with wvrobotics namespace in the root directory

## Utilities List
### WVPIDController
This implements a simplistic PID Controller that is used by our team. The `Tick()` method is intended to be called periodically, preferably within the `Execute()` method of a Command. The `Tick()` method performs all PID Calculations based on an input (the parameter), and returns a calculated PID Signal
