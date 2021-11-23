## Problem:
Write a multithreaded program that outputs prime numbers. This program should work as follows: The user will run the program and will
enter a number on the command line. The program will then create a
separate thread that outputs all the prime numbers less than or equal to
the number entered by the user.


## Running the program:
The program `P4_23_main_code.c` uses the pthread library and the program `P4_23_main_code.cpp` uses the thread library of C++.

The program `P4_23_main_code.cpp` has been tested on windows (VS code editor) by including the header files `mingw.thread.h` and `mingw.invoke.h`.
These 2 header files have been taken from <a href="https://github.com/meganz/mingw-std-threads.git">this</a> repository.

## Solution
Two approaches to the solution to the problem are present in the files, `P4_23_code1.c` and `P4_23_code2.cpp`. 

### Solution 1 (`P4_23_code1.c`)
This uses the pthread library to create and manage threads.

#### Executing the file
To execute the file `P4_22_code1.c` on Linux:
```
gcc P4_23_code1.c -pthread
./a.out
```

#### Sample inputs and outputs:
Input:
```
Enter the value of the number: 1000
```
Output:(can be different for different set of executions):
```
The prime numbers less than or equal to 1000 are:
101 103 107 109 113 127 131 137 139 149 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 353 359 367 373 379 383 389 397 401 307 409 311 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 313 503 509 521 317 523 331 541 337 347 547 349 557 563 569 571 577 587 593 599 601 607 613 617 619 631 641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 809 811 821 823 827 829 839 853 857 859 863 877 907 881 911 883 919 887 929 937 941 947 751 757 761 769 773 787 797 953 967 971 977 983 991 997 
```
#### Screenshot from my terminal:
<img src="" width="500" height="100" />


### Solution 2 (`P4_23_code2.cpp`)
This uses the thread library to create and manage threads.

#### Executing the file
To execute the file `P4_23_code2.cpp` on Linux:
```
g++ -std=c++11 P4_23_code2.cpp -lpthread
./a.out
```

#### Sample inputs and outputs:
Input:
```
Enter the value of the number: 1000
```
Output:
```
The prime numbers less than or equal to 1000 are:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541 547 557 563 569 571 577 587 593 599 601 607 613 617 619 631 641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751 757 761 769 773 787 797 809 811 821 823 827 829 839 853 857 859 863 877 881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997
```
#### Screenshot from my terminal:
<img src="" width="500" height="100" />

## References:
The code in `P4_23_code1.c` and `P4_23_code2.cpp` are not taken from anywhere. I have referred to <a href="https://stackoverflow.com/questions/26090901/find-prime-numbers-in-a-separate-thread">this</a> link and other tutorials mentioned in the file <a href="https://github.com/Sharvani2002/CS252-Assignment/blob/main/thread.md">`thread.md`</a> to understand the syntax and the pthread functions. 
