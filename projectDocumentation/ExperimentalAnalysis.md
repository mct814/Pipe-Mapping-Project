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
Our second experiment was designed to test the accuracy of the probe and to see if the data gained produces a plot. The constraint we are measuring is whether or not our probe maps the path of the pipe within a 1" radius of the actual pipe's edge, and our mapping software produces a plot of the pipe path using the gathered data. We found that with our first iteration of the probe we could not get it to fit inside the 2" pipe (discussed further in the analysis & recommended improvements seciton below) so we decided to run the probe directly over four separate paths mapped out by duct tape, path one is a straight line, path two is a flat right angle with two equal legs, path 3 is a straight flat path that then leads up the wall to produce another right angle, and the fourth path was a straight line where we turned the probe repeatedly. The mapping software had to be adjusted with each new run, as we were feeding raw data to the software, so the threshold, sample rate and FPS had to be recorded each run. The resulting error from each run was calculated in the mapping software by using the current position vs. the original position to continually calculate the error throughout mapping, and since the plot is made using dead reckoning there will be a small bit of error with only IMU data. The results of our experimentation are recorded below.

| Network Number & Run Number  | Probe Total Error (%)  | Sample Rate (Hz) | Threshold  | FPS (frames per second)  |
| ------------ | ------------ | ------------ | ------------ | ------------ |
| 1-1  | 99.35 | 26  |  0.65 | 26  |
| 1-2  |  98.24 | 26 |  0.65 | 26  |
| 1-3  | 99.85 |26 |  0.65 | 26  |
| 2-1  |    97.43 | 26 |  0.6 | 26  |
| 2-2  | 98.43 | 26 |  0.6 | 26  |
| 2-3  |  92.378 | 26 |  0.6 | 26  |
| 3-1  |  79.72 | 26 |  7 | 26  |
| 3-2  |  78.24 |26 |  0.6 | 26  |
| 3-3  |  99.54 | 26 |  13.2 |  26 |
| 4-1  |  531 | 26 |  16 |  26 |
| 4-2  |  51.5 | 26 |  16 |  26 |
| 4-3  |  583.07 | 26 |  16 |  26 |

| Network Number & Run Number |Probe Total Error Without Gyro(%) |
| ---------------- | ------------- |-----------|
| 1-1  | 34.47  |
| 1-2  | 44.3  |
| 1-3  | 1.18  |


![image](https://user-images.githubusercontent.com/104523603/200982051-b92cbcc4-16ce-4687-b461-a7d30f94b8a3.png)
![image](https://user-images.githubusercontent.com/104523603/200993233-3b647f7d-a788-49e7-82bb-e614677169ce.png)
![image](https://user-images.githubusercontent.com/104523603/200993689-86fcf534-772f-4508-817a-bdd16613aede.png)

![image](https://user-images.githubusercontent.com/104523603/200993395-b38f6043-0755-43f0-99af-31c03d5f6f59.png)

### Analysis & Recommended Improvements
Since the error ranges from 583%-78% it does not meet our 1" goal for the error range, ways to mitigate this would be to have a second IMU to prevent incorrect data from being used, have the probe be tested using a machine so that the tests are repeatable so we could check for inconsistencies easier, run the IMU data through a filter before calculating the error, and having a setup where the gyro won't accendentally turn where it changes how the plot forms. and corresponding to the fact that there will always be some error with just an IMU, this could be mitigated in the future by connecting a GPS or other secondary sensor or unit, as with IMUs it is difficult to measure a decline/incline in a path. The IMU and machine fixes will be able to be used with the updated probe design

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
The memory subsystem was well able to hold the necessary data needed for the IMU outputs. Recommended improvements are purely to increase the performance of the system and convenience of the programmer. The only improvement that the team could find was to change the memory to be able to be written to without being erased. The current memory has to be erased everytime you want to change the data in a byte so this caused a bit of a performance hit on the system. It was not enough to change the data but if we sampled at a higher frequency, it would have caused a problem.

## Experiment 4
The fourth experiment focused on verifying that the device's battery life was within the specification defined within previous documents. This specification stated that the batteries must last long enough for the probe to collect 20 minutes worth of data at minimum. For this experiment, the device was powered only via the series connection of 3 AA batteries connected to the Vin and GND pins of the Arduino Nano. Load current was measured using a DMM, and then the initial battery voltage was measured. After recording the initial battery voltage, the device was allowed to continuously poll data for 40 minutes uninterrupted. After the 40 minutes were up, the battery voltage was measured again. The data is shown in the table below. 

| Run Time | Initial Battery Voltage (V) | Post-test Battery Voltage (V) | Load Current (mA)|
| -------- | --------------------------- | ----------------------------- | ------------ |
| 40 minutes | 5.08 | 4.98 | 15-18 |

 Given the initial specification of 20 minutes minimum run time, this experiment verifies that the device comfortably meets our requirements. It should be noted that due to the dropout voltage of the 3.3V LDO, the device will only remain powered until the total battery voltage reaches around 3.67V (as calculated in the Power Subsystem Signoff). However, even though the device will only be functional until the battery voltage approaches this threshold, it is clear that the device exceeds our minimum run time requirement. Given the load current in the table above, and the manufacturer discharge curve for the batteries used in this experiment shown below (Duracell Coppertop AA's), we can estimate the battery life of the device to be around 50-100 hours when using these batteries.
 
![image](https://user-images.githubusercontent.com/104386626/200984283-4bcc3110-0184-46d8-bb12-8822c4c99d47.png)

Battery Discharge Curve (device will function until the voltage of each battery reaches around 1.22V)
