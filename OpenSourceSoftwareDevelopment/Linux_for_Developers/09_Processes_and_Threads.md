# Processes and Threads

A process is a running instance of a program and contains information about environment variables, file descriptors and current directtory, etc.
It can contain one or more **threads**, each of which has the same process ID and shares the same environment, memory regions (except for stack), etc.
While Linux permits thread (or process) creation through the low level **clone()** system call, the mos usual method is to use **pthread_create()** which is part of the standard **POSIX Threads (ppthreads)** library.

## Implementation of pthreads
*In a perfect world, any pthreads compliant program should be write once, use anywhere*.

