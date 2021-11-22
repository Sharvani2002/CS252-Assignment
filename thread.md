### pthreads
POSIX Threads is an API defined by the standard POSIX.1c, Threads extensions (IEEE Std 1003.1c-1995).
pthreads or POSIX threads allows one to spawn a new concurrent process flow. It is most effective on multi-processor or multi-core systems where the process flow can be scheduled to run on another processor thus gaining speed through parallel or distributed processing. Implementation of pthread is available with gcc compiler.

The `pthread.h` header file needs to be included at the beginning of the script to use all the functions of the pthreads library.  
`-pthread` or `-lpthread` can be used in the command line while compiling and linking the file in order to execute the c file.

### POSIX threads for windows:
As windows does not support the pthreads standard natively we can make use of the following:
- `Pthreads4w` project provides a portable and open-source wrapper implementation. It can also be used to port Unix software (which uses pthreads) with little or no modification to the Windows platform. 
Pthreads4w version 3.0.0 or later, released under the Apache Public License v2.0, is compatible with 64-bit or 32-bit Windows systems. Version 2.11.0, released under the LGPLv3 license, is also 64-bit or 32-bit compatible.
- The `Mingw-w64` project also contains a wrapper implementation of pthreads, `winpthreads`, which tries to use more native system calls than the Pthreads4w project.


Some of the functions defined in the pthreads library are:
- `pthread_create`<br>
This function can be used to create a new thread.
- `pthread_self`<br>
This function can be used to obtain the thread id of the current thread.
- `pthread_detach`<br>
This function marks the thread identified as detached. When a detached thread terminates, its resources are automatically released back to the system without the need for another thread to join with the terminated thread. Attempting to detach an already detached thread can result in unspecified behavior. It returns 0 on success and error number on error.
- `pthread_equal`<br>
This function can be used to compare if two threads. If they are equal, it returns a non zero value (otherwise it will return zero).
- `pthread_cancel`<br>
This function can be used to send a cancellation request to a thread.
- `pthread_exit`<br>
This function is used to explicitly exit a thread. If the thread is joinable, it returns a value via `retval` that is available to another thread in the same process that calls
 `pthread_join()`. The value pointed to by retval should not be located on the calling thread's stack, since the contents of that stack are undefined after the thread terminates.
- `pthread_join`<br>
This blocks the calling thread until the specified thread terminates. When a thread is created using `pthread_create()`, one of its attributes defines whether it is joinable or detached. Only threads that are created as joinable can be joined. If a thread is created as detached, it can never be joined (default state is joinable). It returns 0 on success and error number on error.
<br>
Some points to note:

- If `main()` finishes before the threads it has created, and exits with `pthread_exit()`, the other threads will continue to execute. Otherwise, they will be automatically terminated when main() finishes.
- The `pthread_exit()` function never returns. If the thread is not detached, the thread id and return value may be examined from another thread by using `pthread_join`.
- Joinable threads must be terminated by other threads (using `pthread_join`) in order to free memory resources. Detached threads cannot be reaped or killed by other threads, and resources are automatically reaped on termination. 
<!-- - So unless threads need to synchronize among themselves, it is better to call `pthread_detach(pthread_self());` instead of `pthread_join`. -->
- The detached attribute merely determines the behavior of the system when the thread terminates. It does not prevent the thread from being terminated if the process terminates using exit() or equivalently, if the main thread returns.
- Either `pthread_join()` or `pthread_detach()` should be called for each thread that an application creates, so that system resources for the thread can be released. Note that the resources of any threads for which one of these actions has not been done will be freed when the process terminates.
- Failure to join with a thread that is joinable produces a zombie thread. Each zombie thread consumes some system resources, and when enough zombie threads have accumulated, it will no longer be possible to create new threads (or processes).
- Performing a return from the start function of any thread other than the main thread results in an implicit call to `pthread_exit()`, using the function's return value as the thread's exit status.
 


### References
This document contains my understanding about pthread library and its functions. I had referred some websites to understand about pthreads:<br>
https://en.wikipedia.org/wiki/Pthreads <br>
https://www.geeksforgeeks.org/thread-functions-in-c-c/ <br>
https://man7.org/linux/man-pages/man3/pthread_detach.3.html <br>

<a href="https://docs.google.com/document/d/1sjiPWxjO6kNHuu8abBb3OAKYutqJIRi0ams3mujcOrU/edit?usp=sharing">This</a> link contains my notes related to the threads topic and implementation.
