### pthreads
POSIX Threads is an API defined by the standard POSIX.1c, Threads extensions (IEEE Std 1003.1c-1995).
pthreads or POSIX threads allows one to spawn a new concurrent process flow. It is most effective on multi-processor or multi-core systems where the process flow can be scheduled to run on another processor thus gaining speed through parallel or distributed processing. Implementation of pthread is available with gcc compiler.

The `pthread.h` header file needs to be included at the beginning of the script to use all the functions of the pthreads library.  
`-pthread` or `-lpthread` can be used in the command line while compiling the file in order to execute the c file.

### POSIX threads for windows:
As windows does not support the pthreads standard natively we can make use of the following:
- `Pthreads4w` project provides a portable and open-source wrapper implementation. It can also be used to port Unix software (which uses pthreads) with little or no modification to the Windows platform. 
Pthreads4w version 3.0.0 or later, released under the Apache Public License v2.0, is compatible with 64-bit or 32-bit Windows systems. Version 2.11.0, released under the LGPLv3 license, is also 64-bit or 32-bit compatible.
- The `Mingw-w64` project also contains a wrapper implementation of pthreads, `winpthreads`, which tries to use more native system calls than the Pthreads4w project.




### References
Here are some links which I referred to understand abot pthreads:
https://en.wikipedia.org/wiki/Pthreads
