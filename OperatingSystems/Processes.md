One of the most basic operating system abstractions is a process.
A program can be thought of as a set of instructions waiting to be run. Once the OS runs the program, it becomes a process.

CPU virtualization requires low-level hardware and high-level intelligence to be done properly.
- Mechanisms are low-level protocols or techniques that complete the required tasks.
- Policies are algorithms that decide how to handle the numerous requests and limited resources.
For example, the scheduling policy will often decide which program to run and how to run them.

Which parts of a machine are required for running a program?

- Memory encompasses the data and instructions read and written by the executing program. The address space is the memory that the process can access.
- Registers are another part of a process’s machine state. They fetch, decode, and execute instructions.
Some registers of note are:
A Program Counter contains the memory address of the next instruction.
- A stack pointer and a frame pointer are used to manage the stack in relation to parameters, variables, and return addresses.
- Persistent storage devices are used to store information such as all of the open files for a process.

Once a process is created, it can be in one of three different states:
- Running: A process is executing instructions on the CPU.
- Ready: A process is ready to run, but it is not yet being executed on the CPU.
- Blocked: A running process is stopped until another event happens.

When a process moves from ready to running, it is said to be scheduled. A descheduled process moves from running to ready.
The Process Control Block (PCB) is another data structure used to hold information about each process.
This data structure is also known as the process descriptor.

## Summary
A process is an OS abstraction for a running program. It can be described by:
The state
Which includes Running, Ready, and Blocked
The contents of its address space
The contents of its CPU registers
Which includes the program counter and the stack pointer
The I/O information
Which includes files that are open and files that can be read or written
The process list includes all of the processes in the system.
The process control block (PCB), is a data structure that stores information about a particular process.

### Additional Flags
There are a few other important flags to be aware of:
-s SEED, --seed=SEED the random seed
this gives you way to create a bunch of different jobs
randomly
-L IO_LENGTH, --iolength=IO_LENGTH
this determines how long IOs take to complete (default is 5
ticks)
-S PROCESS_SWITCH_BEHAVIOR, --switch=PROCESS_SWITCH_BEHAVIOR
when to switch between processes:
SWITCH_ON_IO, SWITCH_ON_END
this determines when we switch to another process:
- SWITCH_ON_IO, the system will switch when a process issues
an IO
- SWITCH_ON_END, the system will only switch when the
current process is done
-I IO_DONE_BEHAVIOR, --iodone=IO_DONE_BEHAVIOR
type of behavior when IO ends:
IO_RUN_LATER, IO_RUN_IMMEDIATE
this determines when a process runs after it issues an IO:
- IO_RUN_IMMEDIATE: switch to this process right now
- IO_RUN_LATER: switch to this process when it is natural to
(e.g., depending on process-switching behavior)
