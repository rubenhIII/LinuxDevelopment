# Loading and Unloading Kernel Modules

Many facilities in the Linux kernel can either be built-in to the kernel when it is initially loaded, or dynamically added (or removed) later as modules, upon need or demand. Such modules may or may not be device drivers. Even in cases where the functionality will virtually always be needed, incorporation of the ability to load and unload as a module facilitates development, as kernel reboots are not required to test changes.
Linux retains a monolithic kernel architecture, rather than a microkernel one. This is because once a module is loaded, it becomes a fully functional part of the kernel, with few restrictions. It communicates with all kernel sub-systems primarily through shared resources, such as memory and locks, rather than through messages passing as might a microkernel.

Module loading and unloading must be done as the root user.

> $ sudo /sbin/insmod \<pathto\>/module\_name.ko

A kernel module always has a file extension **.ko**. Many modules can be loaded while specifying parameters values. While the module is loaded, you can always see its status with the **lsmod** command. 

Direct removal can alwayss be done with:

> sudo /sbin/rmmod module\_name

In most circumstances, the **insmod** and **rmmod** commands are not usually used to load/unload modules, but rather the **modprobe** command us, as in:

> sudo /sbin/modprobe module\_name  
> sudo /sbin/modprobe -r module\_name

For **modprobe**, the modules must be installed in the proper location, generally under **/lib/modules/$(uname -r)** where **$(uname -r)** gives the current kernel version. The **modinfo** command can be used to find out information about kernel modules, whether they are loaded or not.
