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
Our second experiment was designed to test the accuracy of the probe along with the battery life and memory size. Our three constraints being tested here are that the memory can hold up to 20 minutes of data, our battery lasts at least 20 minutes or 1200 sec, and our probe maps the path of the pipe within a 1" radius of the actual pipe's edge. We found that with our first iteration of the probe we could not get it to fit inside the 2" pipe (discussed further in the analysis & recommended improvements seciton below) so we decided to run the probe along the edge of the pipe and measure the accuracy of the probe against the real life position of the top edge of the pipe network. We then allow the probe to run for at least 20 minutes and record whether or not the memory overflowed and whether or not the battery died. The results of our experimentation are recorded below.

| Network Number & Run Number   | Time (sec)  | Probe Error (m)  | Memory Overflow (yes or no)  | Battery Dead (yes or no)  |
| ------------ | ------------ | ------------ | ------------ | ------------ |
| 1-1  | 1200  |  0.482 | No  | No  |
| 1-2  |  1200 |  0.846 | No  | No  |
| 1-3  |  1200|  0.763 | No  | No  |
| 2-1  |   1200|  0.117 | No  | No  |
| 2-2  |   1200|  0.296 | No  | No  |
| 2-3  |   1200|  0.956 | No  | No  |
| 3-1  |   1200|  0.600 | No  | No  |
| 3-2  |   1200|  0.219 | No  |  No |
| 3-3  |   1200|  0.301 |  No |  No |

### Analysis & Recommended Improvements
Since the error ranges from 4.6" to 37.6" it does not meet our 1" goal for the error range, ways to mitigate this would be to have a second IMU to prevent incorrect data from being used, have the probe be tested using a machine so that the tests are repeatable to check for inconsistencies easier, or to run the IMU data through a filter before calculating the error.


