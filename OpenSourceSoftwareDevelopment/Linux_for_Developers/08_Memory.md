# Memory

Linux uses a virtual memory system(VM), as do all modern opeating systems: the virtual memory is larger than the physical memory.
Each process has its own, proctected addess space. Addresses are virtual and must be traslated to and from physical address by the kernel whenever a process needs to access memory.
The kernel itself also uses virtual addresses; however the translation can be as simple as an offset depending on the architecture and the type of memory being used.
The kernel allows fair shares of memory to be allocated to every running process, and coordinates when memory is shared among processes. In adittion, mapping can be used to link a file directly to a process's virtual address space. Furthermore, certain areas of memory can be protected against writing/and or code execution.

> **free** utility gives a very terse report on free and used memory in your system.

While Linux permits up to 64 GB of memory to be used on 32-bit systems, the limit per process is a little less than 3 GB. This is because is only 4 GB of address space and the topmost GB is reserved for kernel addresses. The little is somewhat less than 3 GB because of some address space being reserved for memory-mapped devices.

## Swap

Linux explos a virtual memory system in which the operating system can function as if it had more memory than it really does. This kind of memory overcommission functions in two ways:
- Many programs do not actually use all the memory they are given permission to use. Sometimes, this is because child processes inherit a copy of the parent's memory regions utilizing a COW (Copy on Write) technique, in which the child only obtains a unique copy (on a page-by-page basis) when there is a change.
- When memory pressure becomes important, less active memory regions may be swapped out to disk, to be recalled only when needed again.


