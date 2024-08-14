# What does an Operating System do?
- Takes physical resources (CPU, memory, disk, etc) and virtualizes them.
- Manages the shared memory between programs.
- Handles tough issues related to concurrency.
- Stores files persistently, making it safe for the long-term.

## Design Goals
Now, we should have an idea of what an OS does.
- Takes physical resources (CPU, memory, disk, etc) and virtualizes them.
- Handles tough issues related to concurrency.
- Stores files persistently, making it safe for the long-term.

Since we want to build OS’s we want to focus our design goals and make necessary trade-offs for the most efficient system.
- Build up abstractions to make the system easy to use.
- Provide high-performance, or minimize the overheads
- Provide protection and prevent bad behavior between applications, as well as between the OS and applications
    - Isolation is the core of protection, and accounts for a lot of what the OS has to do.
- Our OS must be reliable, as all applications fail if the OS fails.
- Energy-efficiency is important, because our resources are limited.
- Our OS should be secure, and protect against harmful applications.
- Our OS should have Mobility, as OSs are running on smaller devices
- The OS will have various goals depending on how the system is used and will likely be built in slightly different ways. It’s okay though, because many of the ideas we will explore on creating an OS apply to a wide range of devices.
