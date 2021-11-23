## Problem description:

Write a multithreaded program that calculates various statistical values
for a list of numbers. This program will be passed a series of numbers
on the command line and will then create three separate worker threads.
One thread will determine the average of the numbers, the second will
determine the maximum value, and the third will determine the minimum value. For example, suppose your program is passed the integers
```
90 81 78 95 79 72 85
```
The program will report
```
The average value is 82
The minimum value is 72
The maximum value is 95
```
The variables representing the average, minimum, and maximum values
will be stored globally. The worker threads will set these values, and
the parent thread will output the values once the workers have exited.
(We could obviously expand this program by creating additional threads
that determine other statistical values, such as median and standard
deviation.)

## Solution
The solution to the problem is in the c file, `P4_22_code1.c`. This uses the pthread library to create and manage threads. It uses the math library for computing the statistical values.

## Executing the codes
To execute the file `P4_22_code1.c` on Linux:
```
gcc P4_22_code1.c -lm -pthread
./a.out
```

## Sample inputs and outputs:
Input:
```
Enter the number of numbers: 4
Enter the numbers: 
2 4 3 5
```
Output:
```
The average value is 3.500000
The minimum value is 2
The maximum value is 5
The median value is 3.500000
The standard deviation is 1.118034
```
### Screenshot from my terminal:
<img src="https://drive.google.com/file/d/1htJWDs3Nr54uD5_N7mv6KWYUdIX1ECii/view?usp=sharing" width="500" height="100" />


## References:
The code in `P4_22_code1.c` is not taken from anywhere. I have referred to <a href="https://gist.github.com/Jabiribn/e58bf13c678953891900e5f982b48037">this</a> gist and other tutorials/resources mentioned in `thread.md`.
