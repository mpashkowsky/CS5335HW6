# CS5335HW6

Youtube Video: https://youtu.be/OsvHDcx3gZw

Note: Hello There
I am Matthew Pashkowsky
This is my submission for HW 6 for CS5335
OBS needs driver updates and I do not know how to do that
SimpleScreenRecorder is the only recorder I could get to record my screen, but it doesn’t record my audio


For HW 6, I edited how the robot sent data to the viz code and how the viz code handled data. The problem with the initial brain code is that the robot sends data to the viz code relative to itself. This meant that the visualization always produced spokes of a wheel coming out from the center. In order to combat this, the range data from the LIDAR was broken down into x and y components. These components could then be added to the respective x and y positions of the robot that took the measurements, yielding an x,y coordinate for wall. The viz code was then also changed to accept x and y coordinates instead of a magnitude and an angle, which is reasonable given that the viz code already had to change the data it received into x and y coordinates.

However, I was unable to get this data to actually appear on the visualization. The starter code was not very helpful, and I was unable to get OpenGL to work properly.

I did not change the robot movement code as that code still directed the robot to avoid walls and explore the area (going into at least 4 rooms), meaning that for my purposes it seemed satisfactory.
