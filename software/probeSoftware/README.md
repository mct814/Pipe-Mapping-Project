# Probe Software

## Functionality
The probe software should be loaded onto the arduino. This software is not written for the redesign, but for the current debug state of the previous board. If you use this software with the new board, you need to change the GPIO pin numbers.

Software states:
* Short pin D9 and D8 to read from the device
* Short pin D9 and D7 to record data on the device

The software does the following.
* Setup the Serial communication (57600).
* Setup the IMU
    * Set the accelerometer and gyroscope poll speed to 52 Hz.
    * Set the FIFO to FIFO mode
    * Set the FIFO to set the full bit at 128 bytes.
    * Enable the Timestamp counter
* Setup the Memory
    * Set pcConnected to true
    * Set pcConnected to false, and erase the memory if recording new data
* Program Loop
    * IF pcConnected is false
        * Get the number of entries in the fifo
        * Store the data in the fifo into memory one page at a time (The memory only supports writing a maximum of 256 bytes at a time)
    * IF pcConnected is true
        * Get the number of entries saved in memory
        * Read the information in on continuous read (supported by current memory chip)
        * Send the information to the pc through the USB cable 

## Dependecies
The only dependencies are the Arduino SoftwareSerial and SPI libraries.

## How to install / run
Load this software file into the arduino software and send it to the device.