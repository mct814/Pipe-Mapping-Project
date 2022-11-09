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
One problem that we encountered with this system is that while the battery shell easily traversed the network, the PCB shell often got stuck in the 2" 90 degree elbows due to a small lip that was not forseen in our initial design. Our next step is to redesign the PCB shell to have a more gradual edge rather than being very nearly a perfect cylinder. It is likely that both the battery shell and PCB shell would fit in a larger diameter PVC system but our cost for testing would have had to be much higher to confirm that theory. What this experiment verified was that our mechanical subsystem pulls at or above our minimum velocity (1 ft/sec) and pulls consistently with very little deviation so as to minimize the error during data collection. While we did not have a specific number constraining our velo

## Experiment 2
Our second experiment was designed to test the accuracy of the probe. The constraint we are measuring is whether or not our probe maps the path of the pipe within a 1" radius of the actual pipe's edge, and our mappping software produces a plot of the pipe path using the gathered data. We found that with our first iteration of the probe we could not get it to fit inside the 2" pipe (discussed further in the analysis & recommended improvements seciton below) so we decided to run the probe along the edge of the pipe and measure the accuracy of the probe against the real life position of the top edge of the pipe network.  The mapping software had to be adjusted with each new run, as we were feeding raw data to the software, so the threshold, sample rate and FPS had to be recorded each run. The resulting error from each run was calculated in the mapping software by using the current position vs. the original position to continually calculate the error throughout mapping, and since the plot is made using dead reckoning there will be a small bit of error with only IMU data. The results of our experimentation are recorded below.

| Network Number & Run Number  | Probe Error (in)  | Sample Rate (Hz) | Threshold  | FPS (frames per second)  |
| ------------ | ------------ | ------------ | ------------ | ------------ |
| 1-1  | 18.976 | 26  |  0.7 | 26  |
| 1-2  |  33.307 | 26 |  3.25 | 26  |
| 1-3  | 30.039 |26 |  3.5 | 26  |
| 2-1  |    4.606 | 26 |  10 | 26  |
| 2-2  | 11.654 | 26 |  10 | 26  |
| 2-3  |  37.638 | 26 |  7.6 | 26  |
| 3-1  |  23.622 | 26 |  7.5 | 26  |
| 3-2  |  8.622 |26 |  10 | 26  |
| 3-3  |  11.85 | 26 |  12 |  26 |

![image](https://user-images.githubusercontent.com/104523603/200466317-aab59af5-2076-44bc-9e38-b173aed3919f.png)

### Analysis & Recommended Improvements
Since the error ranges from 4.6" to 37.6" it does not meet our 1" goal for the error range, ways to mitigate this would be to have a second IMU to prevent incorrect data from being used, have the probe be tested using a machine so that the tests are repeatable so we could check for inconsistencies easier, or to run the IMU data through a filter before calculating the error. and corresponding to the fact that there will always be some error with just an IMU this could be mitigated in the future by connecting a GPS or other secondary sensor or unit, as with IMUs it is difficult to measure a decline in a path. The IMU and machine fixes will be able it be used with the updated probe design

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
