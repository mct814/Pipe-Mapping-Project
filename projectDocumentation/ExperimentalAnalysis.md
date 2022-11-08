# 3D Pipe Mapping Probe: Experimental Analysis
## Experiment 1
The first experimentation we did was on the mechanical subsystem whcih includes the motors, pipe network, and spool with fishline. The completed experiment consisted of a "dummy" battery holder shell being pulled through the 24 foot long 2 inch diameter PVC network. We then measured how fast the probe was pulled through the PVC network and with that calculated the average speed of the probe (data shown below).
### Speed Of Probe
| Distance (ft) | Time (sec) | Speed (ft/sec) |
| ---------------- | ------------- | ------------------- |
| 24  | 14.06  | 1.714 |
| 24  | 13.89  | 1.727 |
| 24  | 13.86 | 1.731  |

### Analysis & Recommended Improvements
One problem that we encountered with this system is that while the battery shell easily traversed the network the PCB shell often got stuck in the 2" 90 degree elbows due to a small lip that was not forseen in our initial design. Our next step is to redesign the PCB shell to have a more gradual edge rather than being very nearly a perfect cylinder. It is likely that both the battery shell and PCB shell would fit in a larger system but our cost for testing would have had to be much higher to confirm that theory. The good news is that the speed of this system is well above the minimum requirement of 1 ft/sec which means that this specification was well met.

## Experiment 2
Our second experiment was designed to test the accuracy of the probe. The constraint we are measuring is whether or not our probe maps the path of the pipe within a 1" radius of the actual pipe's edge, and our mappping software produces a plot of the pipe path using the gathered data. We found that with our first iteration of the probe we could not get it to fit inside the 2" pipe (discussed further in the analysis & recommended improvements seciton below) so we decided to run the probe along the edge of the pipe and measure the accuracy of the probe against the real life position of the top edge of the pipe network.  The mapping software had to be adjusted with each new run, as we were feeding raw data to the software, so the threshold,sample rate and FPS had to be recorded each run. The results of our experimentation are recorded below.

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
Since the error ranges from 4.6" to 37.6" it does not meet our 1" goal for the error range, ways to mitigate this would be to have a second IMU to prevent incorrect data from being used, have the probe be tested using a machine so that the tests are repeatable so we could check for inconsistencies easier, or to run the IMU data through a filter before calculating the error. The IMU and machine fixes will be able it be used with the updated probe designe
