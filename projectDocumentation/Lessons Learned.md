# Lessons Learned

* Complete all signoffs as soon as possible; it may take a month or two for parts to be delivered.
* If there is a part that is central to the design, such as our NXP microcontroller, either negotiate to order double what is needed, or plan a backup part if the chip/part is defective.
* Research any software you will use as if your system is already constructed. Our modeling software seemed as if it would be simple to do with little error, until we realized that the majority of software needed an extra component e.g Lidar, magnetometer, GPS, ect. This caused many small errors to compound in the process of mapping.
* When at all possible, avoid using leadless IC's when designing a surface-mount PCB. Without the right equipment, it is incredibly challenging to solder correctly.
* If you MUST use leadless SMD components, make sure that you get a stencil for reflow soldering the board. It is absolutely crucial. 
* IMUs often need a secondary chip/part to help reduce error, by 'recentering' the axes of the accelerometer and gyroscope. The team determined that using a set of 9-axis IMUs rather than the 6-axis set we used would greatly assist in keeping the gyroscope measurements accurate. This is certainly a recommended improvement.
