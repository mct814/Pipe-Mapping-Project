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
The second experiment was designed to test the accuracy of the probe and to see if the data measured produced data within our specifications. Our constraints define a successful plot to be within a 1" radius of the measured pipes edge. For this iteration of the experiment it was not possible to measure the probes location from inside of a 2" pipe. Instead, the probe was run over four separate paths defined by duct tape on the floor and walls. For each of the experiments it is assumed that the start location of the probe is (0, 0, 0) on a 3D axis defined as (x, y, z) and the probe is facing the positive y direction.

Each tape line is plotted as the blue line on the graphs, however, a text description is included here as well. The first run consisted of a straight line exactly 6.14 meters long. The second run consisted of a straight line for 3.35 meters, a right turn, and another straight line for 3 meters. The third run consisted of a straight line for 2 meters, a turn upward, and a straight line for 4.14 meters. The fourth run consisted of a straight line exactly 2 meters in length.

The graph below shows the network number and run number for each experiment, the sample rate the data was captured at, the threshold value set in the software, and the final point of the measured data minus the final point of the baseline. The threshold value is set in the software and defines the maximum value an acceleration should have. So anything below that value would be discarded. The difference of the final points is represented as (x, y, z) with each value being the distance between the two points on their respective axis. 

### Mapping Table Using Gyroscope, Accelerometer, and Timestamp Data
| Network Number & Run Number | Sample Rate (Hz) | Threshold | Measured vs Baseline Endpoint Difference |
| - | - | - | - |
| 1 - 1 | 26 Hz | 0.1 | (-13.2, 0.02, 2.32) meters |
| 1 - 2 | 26 Hz | 0.1 | (-11.1, 1.08, 1.02) meters |
| 1 - 3 | 26 Hz | 0.1 | (-11.7, -4.96, 2.22) meters |
| 2 - 1 | 26 Hz | 0.1 | (-5.94, 0.15, 2.72) meters |
| 2 - 2 | 26 Hz | 0.1 | (-19.3, 21.0, 8.72) meters |
| 2 - 3 | 26 Hz | 0.1 | (-19.6, 4.36, 4.76) meters |
| 3 - 1 | 26 Hz | 0.1 | (-99.1, -7.70, -50.3) meters |
| 3 - 2 | 26 Hz | 0.1 | (-12.7, -2.67, -2.18) meters |
| 3 - 3 | 26 Hz | 0.1 | (-29.4, 2.14, -29.8) meters |
| 4 - 1 | 26 Hz | 0.1 | (-87.9, -199.4, -612.3) meters |
| 4 - 2 | 26 Hz | 0.1 | (-24.4, -73.1, -214.1) meters |
| 4 - 3 | 26 Hz | 0.1 | (-18.3, -108.4, -183.8) meters|

It is difficult to represent the deviation throughout the path without having tables full of thousands of data points from the sampling so the graphs below show the baseline (blue) and the measured line (green). The endpoints have been measured to give some metric of how far off the final values are but the intermediate values need to be evaluated graphically. Note in some of the graphed simulations the blue line is difficult to see but it is there.

![image](/projectDocumentation/modelingsubsystem/Pipe1_Runs.png)
![image](/projectDocumentation/modelingsubsystem/Pipe2_Runs.png)
![image](/projectDocumentation/modelingsubsystem/Pipe3_Runs.png)
![image](/projectDocumentation/modelingsubsystem/Pipe4_Runs.png)

### Analysis & Recommended Improvements
Our design has a high amount of variability in the final measurements from endpoints and does not always follow the baseline path shown in the graphs. Even though our simulations show results with a large amount of error, this was to be expected. There have been examples shown with the software solution we are using, and with every example there seems to be a fairly large amount of error, as with other software solutions as well. 

The error originates from four main causes, the first cause is due to the issue with the current probe. The current probe has many wires connected to each part, which causes the probe to move when we gather data.  We attempted to correct this by taping the wires. This helped to mitigate some of the error. We then taped the probe down to a box that we maneuvered through the experiment. This helped to mitigate a lot of the extra rotational error but it did not remove it completely.

The second cause of error is based on the fact that the current version of the probe cannot be attached to a mechanism to be pulled at a constant speed down a path. This lack of constant speed causes issues in the software depiction, as we need to input the speed to get a map with low error between points.

The third cause of error is due to varying problems with the IMU and the error accumulated during integration. Firstly, the gyroscope causes error in the direction and acceleration of the graphed results. The direction is changed because of the slight variations in the gyroscopic measurements. The acceleration is changed since a turning motion would cause the probe to move slightly faster than if it were moving straight. A solution to avoid the gyroscopic noise would be to move the drone a bit faster as to get more pronounced gyroscopic data. This would allow the software to be able to distinguish actual data and noise. Even though this would pose a solution, we are not able to increase the speed as we have calculated the current speed to be the safest for the pipe and the drone.

Secondly, the current IMU has no way to implement zero angular velocity update, which would allow us to calibrate the gyroscope to show zero when the device is not moving. Currently the gyroscope is showing low values that affect our analysis. Due to this we expected to have an amount of drift but the values seen are a lot stronger than the values we estimated. One solution to this would be to implement a magnometer as well, but then the design would need to eliminate extra sources of electromagnetic interferance.

The fourth cause of error, is due to the software using dead reckoning to map the data points. Dead reckoning is at its base an estimation to be able to map a path using the data points, this error will always exist in our program. Dead reckoning uses the position measured and velocity to plot your position.

Dead reckoning (originally called deduced reckoning) will always introduce slight error into the system, one reason is due to the fact that to get the velocity needed for the position calculation, you must integrate the acceleration which adds an unknown C constant. Then to get a position from that velocity it must be integrated again which changes the equation to end in Cx+D where C and D are unknowns. This C and D introduce error, as the number of integrations increases over time to gain the needed positions the error will grow. 

There are two ways to mitigate this error, one is to zero out the error every so often when the software is run and the second is to have a secondary unit such as a GPS, LIDAR, or external sensor to gain the true location so that the error can be calculated out.

Unfortunately, as we are only using data from 6-axis IMUs dead reckoning is the only calculation that was feasible, as our group is only using an accelerometer and gyroscope to gather data. Another fix would be to get a higher quality IMU where it has a secondary unit included. Our code does have error mitigators already added, so to properly lowered the error to near zero we would need to utilize a secondary sensor. 


The error in our experiments is visible in the graphs, however, barring a few of our results the graphs follow the general shape of the baseline, even though it is difficult to see. Our fourth pipe experiment shows how much the gyroscope is affecting our errors in our runs. Since this run was conducted while spinning the probe the most likely cause of this incredible error was the spinning itself. This leads us to believe that when we perform an experiment in the pipe we need to minimize the roll of the device as much as possible.

The math behind this method of calculating velocity and position is not perfect and can accrue a large amount of error for long durations. Our solution was originally planned to mitigate this. However, as we faced many difficulties during implementation, we had to forego components and methods that were going to assist in reducing this error. Due to this we do not meet our 1" goal for the error range, however, we do have ideas on ways to mitigate this error and design a better system.

Firstly, having the second IMU to check measurements and give better filtering data would be extremely helpful and is already implemented in the redesign. Secondly, having the probe fit inside the casing, and thus the pipe, would hopefully give the sensors a more stable and constant environment to record data in. We could mitigate a lot of sudden movements, accidental offsets, and we could keep the speed much more constant. Finally, having secondary systems, like a GPS or magnetometer, would help tremendously since IMUs have difficulty measuring the incline/decline in a path and are sensitive to sudden changes in motion.


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
 
