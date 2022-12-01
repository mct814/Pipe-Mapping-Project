# Motor Controller Subsystem

## Motor Controller Schematic
![Motor Controller Schematic](MotorControllerSchematic.PNG)

## Overall Design
The entire recommended system setup (from the user manual) is modeled below with the motor controller, power supply (battery), and laptop connections shown.


## Motor Controller
#### Component
Roboclaw 2x7a Motor Controller
* [Product Link](https://www.basicmicro.com/Roboclaw-2x7A-Motor-Controller_p_55.html)

#### Relevant Specs
* Compatible with 2 brushed DC motors
* Operates up to 34 V and 15 Amps

#### Analysis
* 	1. Compatible with 2 Brushed DC motors:
	This motor controller is capable of controlling two brushed DC motors as shown in the figure taken from the datasheet above. This system also has a setting for running them in sync with each other as a part of the compatible software (Motion Studio) shown below.
	2. Meets or exceeds the stall current of the motor:
	This motor controller is designed to control two motors up to 34V 7.5 Amps continuous and 34V 15 Amps peak per channel which is well above the 12V 1.8 Amp stall current of each motor. These values were taken from the datasheets of both the motor and motor controller.
	3. Velocity Accuracy, and Variability:
	This controller can be controlled via USB (from data sheet shown above) which eliminates the need for an Arduino or Rasberry Pi for easy velocity control, and is compatible with quadrature encoders as stated in the datasheet which will allow for accurate velocity control regardless of load changes which are expected to occur during our testing. We said in the proposal that we wanted to be able to accurately read data at 1 ft/sec and this controller will allow us to accurately test different probe speeds and how they affect the data collection of the probe by setting a chosen velocity in the settings menu in Motion Studio. Motion Studio also includes the ability to see a real time graph of the velocity changes over time as seen below. The velocity requirement was calculated based on a 3 inch spool which is equal to the one we will be using and a probe linear velocity of 1 ft/sec (calculations in the mechanical subsystem signoff). It was found that the motor needs to reach at least 76.39 RPM. Therefore I have chosen a motor that can reach 170 RPM which is over twice the calculated speed needed for the probe to travel at the required velocity, because this controller provides adequate power to the chosen motor we can deduce that the speed minimum of 1 ft/sec will be easily reached with this controller.


* [Power Calculations](PowerCalc.jpg)
