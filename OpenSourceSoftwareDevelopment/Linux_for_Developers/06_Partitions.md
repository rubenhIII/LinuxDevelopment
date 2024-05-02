# Partitions

Under Linux, disks are divided in partitions.
The historical scheme used on x86 machines provided for up to four primary partitions, which can be created and information is stored about them in the **MBR (Master Boot Record)**.

> SCSI disks can have only up to 16 partitions.

The MBR scheme dates back to the early days of MSDOS, and modern systems use a newer and more powerful and flexible scheme: **GPT (GUID Partition Table)**, which is based on the Unified Extensible Firmware Interface (UEFI), which permits up to 128 partitions. Most but not all UEFI systems can be reconfigured as MBR-based, so even if you have a newer system.

The Linux kernel discovers all pre-attached hard disks during system boot, and there is normally no configuration files required to inform about what is present. In hotplugs situations, the *udev* system will find disks upon insertion in the system and read in their partition tables.

> The command line utility for creating and examining hard disk partitions is **fdisk**; to see all currently attached device, you can do:
>> $ sudo /sbin/fdisk -l

> **fdisk** utility can be used to create and remove partitions and change their type.
**fdisk** does not allow you to move partitions or resize them. It has to be done in two steps: increase the size of the partition, and then increase the filesystem size (for example, with **resize2fs**).Likewise, for decreasing the size, you have to decrease the size of the dilesystem and then the partition.

Partitions can be formatted for various filesystems with the **mkfs** command, or more usually, with specific commands for each type of filesystems. For example, either of the two following commands:

> $ sudo mkfs -t ext4 /dev/sda10  
> $ sudo mkfs.ext4 /dev/sda10

The **gparted** utility (and some equivalents) let you do all these operations in a graphical user-friendly manner.

## Partitioning Considerations

The exact partitioning scheme you use depends on your needs, and is quite flexible. For the most basic commonly used scheme you would have three partitions:

- /boot is relatively small, typically 100-200 MB, and holds kernels and other boot related materials;these files are vital and rarely change, and it is safer to keep them on a separate partition.
- / contains everything else and is as large as you need; depending on your distribution, system files and applications and basic programs and development tools probably chew up 3-8 GB of space.
- The swap partition should be at least as big as the amount of memory on your system; you can use swap files instead of partitions, but this is a weaker method due to both efficiency and stability considerations.

Use of **LVM (Logical Volume Management)** introduces even more flexibility, as many logical volumes can be placed on a group of physical volumes which can span more than one disk in a transparent way. It is easy to dynamically resize and move such partitions. 

