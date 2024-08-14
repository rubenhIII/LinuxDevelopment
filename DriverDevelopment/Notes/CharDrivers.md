# Char Drivers

# The internal representation of Device Numbers

Within the kernel, the ```dev_t``` type (defined in *<linux/types.h>*) is used to hold device numbers (major and minor parts).
The code should make use of a set of macros found in *<linux/kdev_t.h>*. To obtain the major or minor parts of a dev_t, use:

```
MAJOR(dev_t dev);
MINOR(dev_t dev);
```

If you have the major and minor numbers and need to turn them into a dev_t, use:

```
MKDEV(int major, int minor);
```

# Allocating and Freeing Device Numbers

One of the first things the driver needs to do whe setting up a char device is to obtain one or more device numbers to work with it. The necessary function for this task is *register_chrdev_region*, which is declared in *<linux/fs.h>*
 
```
register_chrdev_region(dev_t first, unsigned int count, char *name);
```

Here, ```first``` is the beginning device number of the range you would like to allocate. The minor number portion of first is often 0. ```count``` is the total number of contiguous device numbers you are requesting. Finally, ```name``` is the name of the device that should be associated with this number range; it will appear in */proc/devices* and *sysfs*.

If you will not know exactly which device numbers you will need, the kernel can dynamically-allocate device numbers:

```
int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, 
                        usigned int count, char *name)
```

With this function, ```dev``` is an output-only parameter that will, on successful completion, hold the first number in your allocated range. ```firstminor``` should be the requested first minor number to use; it is usually 0. The ```count``` and ```name``` parameters work like those give to *request_chrdev_region*.

Regardless of how you allocate your device numbers, you should free them when they are no longer in use. Device numbers are freed with:

```
void unregister_chrdev_region(dev_t first, unsigned int count);
```

The usual place to call *unregister_chrdev_region* would be in your module's cleanup function.

Before a user-space program can access one of those device numbers, your driver needs to connect them to its internal functions that implement the device's operations.

## Dynamic Allocation of Major Numbers

Some major device numbers are statically assigned to the most common devices. a list of those devices can be found in *Documentation/devices.txt* within the kernel source tree.
For new drivers, it is suggested to use dynamic allocation to obtain your major device number. The disadvantage of dynamic assignment is that you can not create the device nodes in advance, because the major number assigned to your module will vary. However, once the number has been assigned, you can read it from */proc/devices/*.
To load a driver using a dynamic major number, therefore the invocation of *insmod* can be replaced by a simple script that, after calling insmod, reads */porc/devices* in order to create the special file(s).

The following script to load a moduke that has been assigned a dynamic number, is part of the scull_load scull distribution.

```
!#/bin/sh
module="scull"
device="scull"
mode="664"

# invoke insmod with all arguments we got
# and use a pathname, as newer modutils don't look in . by default
/sbin/insmod ./$module.ko $* || exit 1

# remove stale nodes
rm -f /dev/${device}[0-3]

major=$(awk "\\$2= =\"$module\" {print \\$1}" /proc/devices)

mknod /dev/${device}0 c $major 0
mknod /dev/${device}1 c $major 1
mknod /dev/${device}2 c $major 2
mknod /dev/${device}3 c $major 3

# give appropriate group/permissions, and change the group.
# Not all distributions have staff, some have "wheel" instead.
group="staff"
grep -q '^staff:' /etc/group || group="wheel"

chgrp $group /dev/${device}[0-3]
chmod $mode /dev/${device}[0-3]
```

The next code based on *scull*'s source can be used for major number asignment:

```
if (scull_major){
    dev = MKDEV(scull_major, scull_minor);
    result = register_chrdev_region(dev, scull_nr_devs, "scull");
} else {
    result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs,
    "scull");
}
if (result < 0) {
    printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
    return result;
}
```
## Data Structures in Driver operations

Most of the fundamental driver operations involve three importanr data structures, called **file_operations**, **file** and **inode**. 

### File Operations
The ```file_operations``` structure is how a char driver sets up a connection with a reserved device number for our use. The structure is defined in ```<linux/fs.h>```, and it is a collection of fuction pointers. Each open file (represented internally by a file structure) is associated with its own set of functions (by including a field called ```f_op``` that points to a ```file_operations``` structure). The operations are mostly in charge of implementing the system calls and are therefore, named *open*, *read*, and so on. Conventionally, a ```file_operations``` structure or a pointer to one is called ```fops```.

### The file Structure
```struct file```defined in ```<linux/fs.h>```, is the second most importanr data structure used in the device drivers. Here, file has nothing to do with the FILE pointers of user-space programs.

The file structure represents an *open file*. (It is not specific to device drivers; every open file in the system has an associated struct file in the kernel spacce.) It is created by the kernel on *open* and is passed to any function that operates on the file, until the last close. After all instances of the file are closed, the kernel releases the data structure.

In the kernel sources, a pointer to struct file is usually called either file or filp ("file pointer").

### The inode Structure
The *inode* structure is used by the kernel internally to represent files. Therefore, it is different from the file structure that represents an open file descriptor. There can be numerous file structures representing multiple open descriptors on a single file, but they all point to a single inode structure.

the inode structure contains a great deal of information about the file. Only two fields of this structure are of interest for writing driver code:
- dev_t i_rdev
For inodes that represent device files, this field contains the actual device number.
- struct cdev *i_cdev
struct cdev is the kernel's internal structure that represents char devices; this field contains a pointer to that structure when the inode refers to a char device file.

As a way of encouraging more portable programming, the kernel developers have added two macros that can be used to obtain the major and minor number from an inode:

```
unsigned int iminor (struct inode *inode);
unsigned int imajor (struct inode *inode);
```

## Char Device Registration
The kernel uses structures of type struct cdev to represent char devices internally. Before the kernel invokes your device's operations, you must allocate and register one or more of these structures. To do so, your code should include ```<linux/cdev.h>```, where the structure and its associated helper functions are defined.

There are two ways of allocating and initializing one of these structures. If you wish to obtain a stand alone cdev structure at run time, you may do so with code such as:

```
struct cdev *my_cdev = cdev_alloc();
my_cdev->ops = &my_fops;
```

If it is needed to embed the cdev structure within a device-specific structure of your own, you should initialize the structure that you have already allocated with:

```
void cdev_init (struct cdev *cdev, struct file_operations *fops);
```
Either way, there is one other struct cdev field that you need to initialize. Like the file_operations structure, struct cdev has an owner field that should be set to THIS_MODULE.

Once the cdev structure is set up, the final step is to tell the kernel avout it with a call to:

```
int cdev_add (struct cdev *dev, dev_t num, unsigned int count);
```
Here, dev is the cdev structure, num is the first device number to which this device responds, and count is the number of device numbers that should be associated with the device.
To remove a char device from the system, call:

```
void cdev_del (struct cdev *dev);
```

