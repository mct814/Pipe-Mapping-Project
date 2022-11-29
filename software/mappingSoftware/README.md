# Mapping Software
The mapping software is an open source project located [here](https://github.com/xioTechnologies/Gait-Tracking) on Github. The underlying algorithm is based on a PhD Thesis from Sebastian O. H. Madgwick from the University of Bristol.

## Functionality
The software reads in the data from a csv file, formatted into columns of data Time, GyrX, GyrY, GyrZ, AccX, AccY, AccZ. More information on the details of the software is provided on the Github page.

## Dependecies
This project is built with Python with the following dependencies.
* dataclasses
* matplotlib
* imufusion
* numpy
* scipy

## How to install / run
Download the gait_tracking.py file, install the dependencies, change the file name in the source code to match the data file, run the program with python.