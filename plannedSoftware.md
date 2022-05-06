# Planned Software
## Microcontroller Software
The microcontroller software is planned to be a C program that repeatedly either:
1) Polls the data from the IMUs and stores them into the memory.
2) Grabs the data from the memory and sends them through the USB connection.

The software action will be chosen by the state switch that the user will use to either record or acquire data using the probe.

## MATLAB
The matlab software will be separated into two sections:
1) Filtering software that will filter out the noise from the acquired data and create the clean positional data needed for mapping.
2) Mapping software will take the clean positional data and map it into a 3D viewable graph / model that will show exactly where the pipes are and where the margin of error lies for each data point.