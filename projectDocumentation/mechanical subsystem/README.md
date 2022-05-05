# Mechanical Subsystem

## Mechanical Schematic
![Mechanical Schematic](MechanicalSchematic.png)

## Overall Design
The entire system is modeled below including the motor, motor bracket (3D printed),
motor stand (2x4 lumber), spool (3D printed), fishline, PVC pipe, and PVC 90 connectors.
The goal is to use this system to get our probe from one end of the pipe to the other. 
This will be achieved by hooking fishline into the grooves of the spool (described further in spool details) 
and attaching that to the probe which is discussed further below. Then the motor on either end of the pipe 
will turn at identical speeds to allow the probe to traverse the pipe at a consistent and controlled speed. 
The PVC network shown in the model is a rough image of what an actual test network may look like; more than 
likely the networks we make will be able to free stand from the ground up to the height of the motor stands 
with most of the PVC laid on the ground. We plan on using a couple of differently shaped pipe networks 
(reusing the same pipe) if possible which will be chosen at the time of testing starting with simple and becoming more complex.


## Motor
#### Component
47:1 Metal Gearmotor 12V with 48 CPR Encoder
* [Product Link](https://www.pololu.com/product/4865)

#### Relevant Specs
* Brushed DC
* Operates at 0.63 N-m of Torque
* Operates at 170 RPM

#### Analysis
* The torque needed was calculated based on a 1lb probe and 30ft of fishline with a 5 inch spool. 
Our probe is likely to be far lighter than 1lb which means torque calculation will be higher than 
what we actually need. Our spool is only 3 inches in diameter which means we will actually need less 
torque than what is calculated. Another aspect of the calculation is friction coefficient; I decided 
to use the friction coefficient of plastic on plastic which should be as high or higher than fishing 
line on PVC. This means again that the final torque calculated will be as high or higher than what we 
actually need. The calculations below first find the friction force of the fishline on the PVC and 
then the force needed to pull a 1lb probe. Then these forces are added together to get the total force 
needed which is then used to calculate torque. The final calculated torque needed to pull a 1lb probe 
through 30ft of PVC with a 5 in spool is about 0.0577 N-m. Therefore I have chosen a motor that produces 
up to 0.62762 N-m which is more than 10x the required minimum torque.

* The RPM requirement was calculated based on a 3 inch spool which is equal to the one we will be 
using and a probe linear velocity of 1 ft/sec. The calculations below convert linear velocity to angular 
velocity and then angular velocity into RPM based on our spool radius of 1.5 in. It was found that the 
motor needs to reach at least 76.39 RPM. Therefore I have chosen a motor that can reach 170 RPM which is 
over twice the calculated speed needed for the probe to travel at the required velocity.

## Motor Mount
#### Component
Custom Motor Mount
* [Design Link](MotorMount.SLDPRT)

#### Relevant Specs
* Custom built to fit the motor chosen which is 25mm in diameter with 2 3mm mounting screws.
* Can be easily screwed into a 2x4 stand like the one in the schematic.

#### Analysis
* [Design Link](MotorMount.SLDPRT) 

## Spool
#### Component
Custom Spool
* [Design Link1](SpoolPt1.SLDPRT)
* [Design Link2](SpoolPt2.SLDPRT)

#### Relevant Specs
* Custom built to fit the motor shaft 4 mm diameter with 0.5 mm key groove.
* 3 inch radius with 5 inch radius walls to keep the fishline spooled without slipping.
* Designed in two parts so that it will be 3D printable.

#### Analysis
* [Design Link1](SpoolPt1.SLDPRT)
* [Design Link2](SpoolPt2.SLDPRT)

## Fishline
#### Component
Clear Fishing Wire
* [Product Link](https://tinyurl.com/y567u27d)

#### Relevant Specs
* 656 Ft of line
* 43 lb Test
* Diameter 0.45 mm 

#### Analysis
* This line will work for our system because our pipe network will only be 30 ft meaning that the maximum 
amount of line we will need is 60 ft. It also has 43 lb test which means that it will be more than strong
enough to pull a 1lb probe through our PVC network.

## PVC
#### Component
2" PVC Pipe
* [Product Link](https://www.lowes.com/pd/Charlotte-Pipe-2-in-dia-x-20-ft-L-280-PSI-PVC-Pipe/3133053)

#### Relevant Specs
* 2" diameter
* 20 ft long

#### Analysis
* This pipe is the industry standard and is within our goal pipe diameter of 1"-4".

## PVC 90s
#### Component
2" PVC 90 degree connectors
* [Product Link](https://tinyurl.com/33px97bh)

#### Relevant Specs
* 2" diameter

#### Analysis
* This 90 degree connector is compatible with the 2" PVC pipe we have chosen for our testing setup.


