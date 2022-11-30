# Redesign

The redesigned PCB is listed under the pcbSubsystem folder. 

## Signoff

This signoff is for the redesign of the pipe mapping drone. It includes the PCB, 2 LDOs, and a new memory chip. 

Components 

5V LDO (link here) 

1.8V LDO (link here) 

Memory (link here) 

GPIO Jumper (link here) 

Each of the components are shown to fit our design and our constraints In previous sign off requests. The 5V LDO is identical to the 1.8V LDO but the output voltage is changed to be able to power the Arduino. 

 

The new PCB does not meet our previous constraints listed in the previous design documents, however, it does fit the new constraints and will fit on top of the Arduino. We are printing a new casing to fit the arduino as well.  

 

5V LDO constraints: 

Power constraint 

The LDO is rated on the datasheet to be able to supply an adequate amount of power to the Arduino nano and the 3V LDO.  

The remaining analysis is shown in the image at the bottom of the page. 

 

PCB constraints: 

Size constraint 

The PCB must be 43.2 mm in length and 18 mm in width. This new PCB design fits this constraint. 

The PCB must fit the Arduino Nano GPIO pins. This new PCB uses the Arduino Nano sizing schematic, and the Eagle files to check against, to ensure that the GPIO pin holes are in the correct location. 

Power constraint 

The PCB has the soldering points to be able to connect to the battery and is connected to the Arduino 5V and GND pins, after the LDO, to be able to power the Arduino as well. 

![LDOAnalysis](/projectDocumentation/redesign/LDOAnalysis.jpeg)