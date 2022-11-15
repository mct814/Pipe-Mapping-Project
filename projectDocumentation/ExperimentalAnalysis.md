# 3D Pipe Mapping Probe: Experimental Analysis
## Experiment 1
The first experimentation we did was on the mechanical subsystem which includes the motors, pipe network, and spool with fishline. The completed experiment consisted of a "dummy" battery holder shell being pulled through the 24 foot long 2 inch diameter PVC network. While the probe was being pulled through we kept a running graph of the instantaneous motor velocity and found the largest difference between the desired velocity and the actual velocity of the motor (data shown below). Screenshots of the graphs have been provided below to show how the data was collected.
### Motor Velocity Graph
#### Run 1 Mid Pipe Snapshot
![image](https://user-images.githubusercontent.com/98492692/200714323-cbae1e80-a144-40de-bcc0-05878fe92b5b.png)
#### Run 2 Beginning Pipe Snapshot
![image](https://user-images.githubusercontent.com/98492692/200714350-74e294f6-bdb9-4d15-babd-2caa8f8abbd8.png)
#### Run 3 Beginning Pipe Snapshot
![image](https://user-images.githubusercontent.com/98492692/200714374-4acea2de-a01f-472b-9856-255e4e054c1a.png)
#### Run 4 End Pipe Snapshot
![image](https://user-images.githubusercontent.com/98492692/200714387-a29ba037-67be-4aa1-b0d1-c20adc2db73c.png)
#### Run 5 End Pipe Snapshot
![image](https://user-images.githubusercontent.com/98492692/200714410-2de6ea51-0291-4e3f-9440-01be22819f8f.png)


### Motor Velocity Deviation Table
| Run Number |Set Velocity (ft/sec) | Maximum Velocity Deviation (ft/sec) |
| ---------------- | ------------- |-----------|
| 1  | 1.39  | 0.016 |
| 2  | 1.36  | 0.060 |
| 3  | 1.34  | 0.038 |
| 4  | 1.41  | 0.019 |
| 5  | 1.27  | 0.052  |

### Analysis & Recommended Improvements
One problem that we encountered with this system is that while the battery shell easily traversed the network, the PCB shell often got stuck in the 2" 90 degree elbows due to a small lip that was not forseen in our initial design. Our next step is to redesign the PCB shell to have a more gradual edge rather than being very nearly a perfect cylinder. It is likely that both the battery shell and PCB shell would fit in a larger diameter PVC system but our cost for testing would have had to be much higher to confirm that theory. What this experiment verified was that our mechanical subsystem pulls at or above our minimum velocity (1 ft/sec) and pulls consistently with very little deviation so as to minimize the error during data collection. While we did not have a specific number constraining our velocity deviation we found that the deviation was always less than 0.1 ft/sec in each of our five tests which means if we run our probe around 1 ft/sec then we will never exceed our maximum velocity of 2 ft/sec which was calculated based on our sampling rate. Therefore this system successfully remained within the constraints while meeting specifications.

## Experiment 2
The second experiment was designed to test the accuracy of the probe and to see if the data measured produced data within our specifications. Our constraints define a successful plot to be within a 1" radius of the measured pipes edge. 

For the following iterations of the experiment, it was not possible to measure the probes location from inside a 2" pipe. Instead, the probe was run over four separate paths defined by duct tape on the floor and walls. For each of the experiments it is assumed that the start location of the probe is (0, 0, 0) on a 3D axis defined as (x, y, z) and the probe is facing the positive y direction.

### Experiment Iteration 1

For the first iteration the tape line is plotted as the orange line on the graphs, however, a text description is included here as well. The first run consisted of a straight line exactly 6.14 meters long. The second run consisted of a straight line for 3.35 meters, a right turn, and another straight line for 3 meters. The third run consisted of a straight line for 2 meters, a turn upward, and a straight line for 4.14 meters. The fourth run consisted of a straight line exactly 2 meters in length.

The graph below shows the network number and run number for each experiment, the sample rate the data was captured at, the threshold value set in the software, and the final point of the measured data minus the final point of the baseline. The threshold value is set in the software and defines the minimum normalized acceleration that would constitute the probe as "moving". The difference of the final points is represented as (x, y, z) with each value being the distance between the two points on their respective axis.

| Network Number & Run Number | Sample Rate (Hz) | Threshold | Measured vs Baseline Endpoint Difference |
| - | - | - | - |
| 1 - 1 | 26 Hz | 0.1 | (13.2, 0.02, 2.32) meters |
| 1 - 2 | 26 Hz | 0.1 | (11.1, 1.08, 1.02) meters |
| 1 - 3 | 26 Hz | 0.1 | (11.7, 4.96, 2.22) meters |
| 2 - 1 | 26 Hz | 0.1 | (5.94, 0.15, 2.72) meters |
| 2 - 2 | 26 Hz | 0.1 | (19.3, 21.0, 8.72) meters |
| 2 - 3 | 26 Hz | 0.1 | (19.6, 4.36, 4.76) meters |
| 3 - 1 | 26 Hz | 0.1 | (99.1, 7.70, 50.3) meters |
| 3 - 2 | 26 Hz | 0.1 | (12.7, 2.67, 2.18) meters |
| 3 - 3 | 26 Hz | 0.1 | (29.4, 2.14, 29.8) meters |
| 4 - 1 | 26 Hz | 0.1 | (87.9, 199.4, 612.3) meters |
| 4 - 2 | 26 Hz | 0.1 | (24.4, 73.1, 214.1) meters |
| 4 - 3 | 26 Hz | 0.1 | (18.3, 108.4, 183.8) meters|

It is difficult to represent the deviation through the path without having tables full of thousands of data points, so the graphs below show the baseline (orange) and the measured line (blue). The endpoints have been measured to give some metric of how far off the final values are, but the intermediate values need to be evaluated graphically. Note in some of the graphed simulations the orange line is difficult to see but it is there.

![image](/projectDocumentation/modelingsubsystem/It1_Pipe1_Runs.png)
![image](/projectDocumentation/modelingsubsystem/It1_Pipe2_Runs.png)
![image](/projectDocumentation/modelingsubsystem/It1_Pipe3_Runs.png)
![image](/projectDocumentation/modelingsubsystem/It1_Pipe4_Runs.png)

### Experiment Iteration 2

For the second iteration the same data from iteration 1 was used. The first iteration shows a large amount of variablility in the final measurements from endpoints and does not always follow the baseline path shown in the graphs. Our first assumption is to test the gyroscope to see if this is the basis of our errors.

Below are graphs and table entries of Pipe 1 and Pipe 2 with the gyroscope data set to 0.

| Network Number & Run Number | Sample Rate (Hz) | Threshold | Measured vs Baseline Endpoint Difference |
| - | - | - | - |
| 1 - 1 | 26 Hz | 0.1 | (0.34, 8.57, 2.30) meters |
| 1 - 2 | 26 Hz | 0.1 | (0.22, 7.51, 1.16) meters |
| 1 - 3 | 26 Hz | 0.1 | (0.17, 9.23, 2.26) meters |
| 2 - 1 | 26 Hz | 0.1 | (0.94, 5.38, 2.65) meters |
| 2 - 2 | 26 Hz | 0.1 | (9.48, 8.07, 1.70) meters |
| 2 - 3 | 26 Hz | 0.1 | (2.76, 4.54, 4.93) meters |

![image](/projectDocumentation/modelingsubsystem/It2_Pipe1_Runs.png)
![image](/projectDocumentation/modelingsubsystem/It2_Pipe2_Runs.png)

Even though our endpoints are closer, the data does not follow the path of the baseline. This led the team to believe that the gyroscope should not be the issue. However, we are not ruling out the possibility.

### Experiment Iteration 3

For the third iteration the team wanted to test whether the speed and acceleration had anything to do with our skewed results. For this a new set of data was generated with new experimentation. The probe was moved along new and old paths similarly to the methods before, except the speed was increased. Initially, the speed was around 0.8 feet per second. The new speed is around 2.5 - 3 feet per second. These values are estimated from the time and distance covered by the retrieved data, we do not have the means to travel at an exact speed since our system can not be intergrated with the mechanical system.

The first pipe was moved along a straight line 9.144 meters in length. The second pipe was moved along the path of pipe 2 in the initial experiments, 3.35 meters straight and 3 meters to the right. For this iteration the gain value was adjusted to get better results. The gain value controls the strength of the gyroscope based error correction on the system.

| Network Number & Run Number | Sample Rate (Hz) | Threshold | Measured vs Baseline Endpoint Difference |
| - | - | - | - |
| 1 - 1 | 26 Hz | 0.21 | 0.55 | (0.63, 1.60, 1.76) meters |
| 1 - 2 | 26 Hz | 0.21 | 0.55 | (2.63, 1.94, 1.08) meters |
| 1 - 3 | 26 Hz | 0.21 | 0.55 | (2.70, 2.00, 1.10) meters |
| 2 - 1 | 26 Hz | 0.12 | 0.55 | (0.94, 5.38, 2.65) meters |
| 2 - 2 | 26 Hz | 0.2 | 0.55 | (1.73, 1.86, 1.73) meters |
| 2 - 3 | 26 Hz | 0.2 | 0.55 | (3.01, 1.05, 0.217) meters |

![image](/projectDocumentation/modelingsubsystem/It3_Pipe1_Runs.png)
![image](/projectDocumentation/modelingsubsystem/It3_Pipe2_Runs.png)

These results look closer to the baseline, however, they are not perfect. This increase in speed has shown to give better data, most likely due to more pronounced data in the IMU. Most experiments using this new iteration turned out similarly to those shown above. The team believes that if the speed was more consistent throughout the experiment the data would be even closer to the baseline.

### Experiment Iteration 4

In the third iteration we increased the speed to obtain better results. Increasing the speed means a faster experiment time, which in turn means less data points in the experiment. Due to this we decided to increase the sampling rate to see if the data would be more defined.

If you increase the sampling rate, you increase the amount of data obtained in the same amount of time. This data then has to be written to the memory for storage. This in turn poses a tradeoff which we had to consider. The faster the sampling rate, the longer the memory would take to write, and the more gaps we would have in the data. The slower the sampling rate, the shorter the memory would take to write, and the more continuous the data would look. Due to this we settled on doubling the sampling rate from 26 Hz to 52 Hz.

| Network Number & Run Number | Sample Rate (Hz) | Threshold | Measured vs Baseline Endpoint Difference |
| - | - | - | - |
| 1 - 1 | 52 Hz | 0.12 | 0.55 | (3.75, 2.92, 0.95) meters |
| 1 - 2 | 52 Hz | 0.21 | 0.35 | (1.00, 2.04, 0.75) meters |
| 1 - 3 | 52 Hz | 0.31 | 0.45 | (2.70, 2.00, 1.10) meters |

![image](/projectDocumentation/modelingsubsystem/It4_Pipe1_Runs.png)

These results show that the increased sampling rate helped with more accurate turns. However, it still wasn't fast enough to show any increased accuracy in the measurements. As stated above, changing the sampling rate provides a tradeoff. The team feels as if 52 Hz was the last possible rating for the IMU that would give decently accurate data without adding large holes in the sampling.

### Analysis & Recommended Improvements
Our initial experimentation showed large amounts of variability in the final measurements from the endpoints and didn't always follow the baseline path. Error was to be expected initially, but not to this degree. We conducted further experiments to isolate the cause of the error. In these further experiments, the gyroscope was ruled out as a culprit and the speed was brought to light. The later experiments still show error in the recordings but we think we have plausible evidence on what is causing the error.

Firstly, the state of the current drone is causing some of the error, or inability to prevent error, that is difficult to mitigate without redesign. The size and fragility of the current probe keeps it from being tested in its originally designed fashion. The probe cannot fit in the pipe since the wires and extra hardware takes up much more space than would fit inside the pipe. The fragility of the wires also prevents us from testing the system with the mechanical subsystem, as the wires are too delicated to risk such an experiment.

Our second source of error is very similar. Due to the fact that we cannot use the mechanical subsystem in the current design, we cannot move the drone at a consistent speed. Experiment iteration 3 shows that increasing the speed gave better results and the team believes a more constant speed would also help after further investigation into the software. 

We have also come to the conclusion that we need to increase the speed of the probe. This is possible, however, we have selected the current speed to be the least damaging to the probe and the pipe. The redesign would need to ensure that the pipe could endure faster speed than previously calculated and that the new casing would be designed to safely travel at those higher speeds.

The last cause of error, is due to the software using dead reckoning to map the data points. Dead reckoning is at its base an estimation to be able to map a path using the data points, this error will always exist in our program. Dead reckoning uses the position measured and velocity to plot your position.

Dead reckoning (originally called deduced reckoning) will always introduce slight error into the system, one reason is due to the fact that to get the velocity needed for the position calculation, you must integrate the acceleration which adds an unknown C constant. Then to get a position from that velocity it must be integrated again which changes the equation to end in Cx+D where C and D are unknowns. This C and D introduce error, as the number of integrations increases over time to gain the needed positions the error will grow. 

There are two ways to mitigate this error, one is to zero out the error every so often when the software is run and the second is to have a secondary unit such as a GPS, LIDAR, or external sensor to gain the true location so that the error can be calculated out.

Unfortunately, as we are only using data from 6-axis IMUs dead reckoning is the only calculation that was feasible, as our group is only using an accelerometer and gyroscope to gather data. Another fix would be to get a higher quality IMU where it has a secondary unit included. Our code does have error mitigators already added, so to properly lowered the error to near zero we would need to utilize a secondary sensor. 

Our solution was originally planned to mitigate some of these errors. However, as we faced many difficulties during implementation, we had to forego components and methods that were going to assist in reducing this error. Due to this we do not meet our 1" goal for the error range, however, we do have ideas on ways to mitigate this error and design a better system.

Firstly, having the second IMU to check measurements and give better filtering data would be extremely helpful and is already implemented in the redesign. Secondly, having the probe fit inside the casing, and thus the pipe, would hopefully give the sensors a more stable and constant environment to record data in. We could mitigate a lot of sudden movements, accidental offsets, and we could keep the speed much more constant. Finally, having secondary systems, like a GPS or magnetometer, would help tremendously since IMUs have difficulty measuring the incline/decline in a path and are sensitive to sudden changes in motion.

Even though the team was not able to get the data within the margins of success, we believe we have determined the cause of the error and have hypothesised on possible fixes to this error. We have taken individual tests of all the subsystems, software, and hardware pieces. The memory is tested in Experiment 3 and shows perfect execution. The software has been tested with example data and shows to be a promising asset. Finally, the IMU is tested in this experiment, however, it is difficult to break down the system any further than we already have. 

We believe that the best way to fix the error in our system would be to move forward with the redesign and conduct the original experiments in the way they were first imagined, with one small change. We would like to run the experiments with varying speeds to truly test what constant speed would give the best results before the sampling rate would need to be increased.


## Experiment 3
The third experiment was designed to test the capabilities of the memory subsystem. We used this experiment to validate that the memory would be able to hold up to 5000 feet or 20 minutes worth of data, and to keep the data when the device was powered off and on. The experiment consisted of running the device for various time lengths, measuring the amount of data that was stored in the memory, verifying that the memory had not overflowed, and verifying that the data was still intact and unmodified.

We were able to use the timestamp provided by the IMU to measure the exact amount of time data was measured. The IMU was running at 26 Hz and polled both the accelerometer, gyroscope, and timestamp. Each data entry consisted of 7 bytes, 1 tag byte and 6 data bytes. Since the data rate and size were constant the data looks exactly as predicted.

| Run Time | Bytes Stored | Bytes Retrieved | Calculated Bytes Remaining In Memory |
| --------- | ------------ | --------------- | ------------------------- |
| 1 minute  | 32,760 bytes | 32,760 bytes    | 16,744,456 bytes          |
| 5 minutes | 163,800 bytes| 163,800 bytes   | 16,613,416 bytes          |
| 10 minutes| 327,600 bytes| 327,600 bytes   | 16,449,616 bytes          |
| 15 minutes| 491,400 bytes| 491,400 bytes   | 16,285,816 bytes          |
| 20 minutes| 655,200 bytes| 655,200 bytes   | 16,122,016 bytes          |

### Analysis & Recommended Improvements
The memory subsystem was easily able to collect data continuously for 20 minutes which is well above what it should ever actually have to collect in a real application. Recommended improvements are purely to increase the performance of the system and convenience of the programmer. The only improvement that the team could find was to change the memory to be able to be written to without being erased. The current memory has to be erased everytime you want to change the data in a byte so this caused a bit of a performance hit on the system. It was not enough to change the data but if we sampled at a higher frequency, it would have caused a problem.

## Experiment 4
The fourth experiment focused on verifying that the device's battery life was within the specification defined within previous documents. This specification stated that the batteries must last long enough for the probe to collect 20 minutes worth of data at minimum. For this experiment, the device was powered only via the series connection of 3 AA batteries connected to the Vin and GND pins of the Arduino Nano. Load current was measured using a DMM, and then the initial battery voltage was measured. After recording the initial battery voltage, the device was allowed to continuously poll data for 20 minutes uninterrupted. After the 20 minutes were up, the battery voltage was measured again. This test was performed 3 times. The data is shown in the table below. 

| Run # | Run Time | Initial Battery Voltage (V) | Post-test Battery Voltage (V) | Load Current (mA)|
| ----- | -------- | --------------------------- | ----------------------------- | ------------ |
| 1 | 20 minutes | 5.08 | 5.03 | 15-18 |
| 2 | 20 minutes | 5.03 | 4.98 | 15-18 |
| 3 | 20 minutes | 4.98 | 4.92 | 15-18 |

 Given the initial specification of 20 minutes minimum run time, this experiment verifies that the device comfortably meets our requirements. It should be noted that due to the dropout voltage of the 3.3V LDO, the device will only remain powered until the total battery voltage reaches around 3.67V (as calculated in the Power Subsystem Signoff). However, even though the device will only be functional until the battery voltage approaches this threshold, it is clear that the device exceeds our minimum run time requirement. Given the load current in the table above, and the manufacturer discharge curve for the batteries used in this experiment (Duracell Coppertop AA's), we can estimate the battery life of the device to be around 50-100 hours when using these batteries.
 
