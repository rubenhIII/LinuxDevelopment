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
