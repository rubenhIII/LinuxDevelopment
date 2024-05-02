# Types of Devices

There are three main types of devices:
- **Character** devices are sequential streams; they mainly implement **open**, **close**, **read**, and **write** functions, e.g. serial and parallel ports (**/dev/ttyS0**, **/dev//lp1**), sound cards (**/dev/dsp0**), etc.
- **Block devices** are randomly accesed only in block size multiples, and I/O operations are usually cached and deal with mounted filesystems, e.g. hard drives partitions (**/dev/sda1**, **/dev/sdb8**), CD-ROMs, etc.
- **Network devices** transfer packets of data, not block or streams, and usually employ a socket interface; packet reception/transmission functions replace read/write operations, and there are no corresponding filesystem nodes; instead, the interfaces are identified by a name, such **eth0** or **wlan0**.

There are also other types of devices, which are classified somewhat differently, according to the type of controller bus they are attached to, such **SCSI (Small Computer Systems Interconnect)** and **USB (Universal Serial Bus)**. These devices share an underlaying protocol regardless of function. Beside the driver for the device itself, hard work goes into writing the driver for the controller hardware which may run many devices.

The character and block devices have filesystem entries associated with them. These nodes can be used by use-level programs to communicate with the device, using normal I/O system calls susch **open()**, **close()**, **read()**, and **write()**.

## /dev Directory
Devices nodes are normallyplaced in the /dev directory and can be created with:

> $ sudo mknod [-m mode] /dev/name \<type\> \<major\> \<minor\>

or from the mknod() system call.
The **major** number identifies the driver associated with the device; all device nodes of the same type (block or character) with the same major number use the same driver.
The **minor** number is used only by the device driver to differentiate between the different devices it may control.

## udev
The **udev** method creates device nodes on the fly as they are needed; there is no need to maintain a ton of devices nodes that will never be used.
The *u* in udev stands for user, and indicates that most of the work of creating, removingm and modifying devices nodes is done in user-space.
udev handles the dynamical generation of device nodes and it evolved to replace earlier mechanisms such as devfs and hotplug.
It supports persistent device naming; names need not depend on the order of device connection or pluggin in,
udev runs as*daemon* and monitors a *netlink* socket.
> When new devices are initialized or removes the uevent kernel facility sends a message through the socket which udev receives and takes approproate action to create or remove device nodes of the right names and properties according to the rules.

The three components of udev are:
- The **libudev** library which allows access to information about devices
- The **udevd** daemon that manages the **/dev** directory
- The **udevadm** utility for control and diagnosis

Themain configuration file is **/etc/udev/udev.conf**; it contains information such as where to place device nodes, default permissions and ownership, etc. By default, rules for device naming are located in the **/etc/udev/rules.d** directory.
