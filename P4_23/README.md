## Problem:
Write a multithreaded program that outputs prime numbers. This program should work as follows: The user will run the program and will
enter a number on the command line. The program will then create a
separate thread that outputs all the prime numbers less than or equal to
the number entered by the user.


## Running the program:
The program `P4_23_main_code.c` uses the pthread library and the program `P4_23_main_code.cpp` uses the thread library of C++.

The program `P4_23_main_code.cpp` has been tested on windows (VS code editor) by including the header files `mingw.thread.h` and `mingw.invoke.h`.
These 2 header files have been taken from <a href="https://github.com/meganz/mingw-std-threads.git">this</a> repository.


## References:
The code in `P4_23_code1.c` and `P4_23_code2.cpp` are not taken from anywhere. I have referred to <a href="https://stackoverflow.com/questions/26090901/find-prime-numbers-in-a-separate-thread">this</a> link and other tutorials mentioned in the file `thread.md` to understand the syntax and the pthread functions. 
