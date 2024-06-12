## Virtual File Systems (VFS)

Linux implements a **Virtual File System (VFS)**, as do all modern operating systems. For the most part neither the specific filesystem or actual physical media and hardware need be addressed by filesystem operations. Furthermore, network filesytems such NFS) can be handled transparently. **This permits Linux to work with more filesystem varieties than any other operating system**. Most filesystems have full read/write access while a few have only read access and perhaps experimental write access.

The native filesystems for Linux are ext2 and its journaling descendants, ext3 and ext4. Each has its associated utility for formatting the filesystem (e.g. mkfs.ext3) and for checking the filesystem (e.g. fsck.ext4). Additianlly, many parameters can be reset or tuned after filesystem creation with the program tune2fs; one can use e4defrag to defragmentation.

## Journaling Filesystems
A *Journaling File System* is a filesystem that keeps track of changes not yet commited to the filesystem's main part by recording the goal of such changes in a data structure known as a *journal*, which is usually a circular log.
Journaling filesystems recoer from system crashes or ungraceful shutdowns with little or no corruption, and they do so very rapidly.
While this comes at the price of having some more operations to do, additional enhacements can more than offset the price.
I a jornaling filesystem, operations are grouped into transactions; a transaction must be completed without error, atomically, otherwise, the filesystem is not changed.
A log dile is maintained of transactions; when an error ocurrs, usually only the last transaction needs to be examined.
### Journaling filesystems freely available under Linux:
- The **ext3** filesystem is an extension of the ext2 filesystem.
- The **ext4** filesystem is a extension of the ext3 filesystem, and was included in the mainline kernel as an experimental branch, and then as a stable production feature in kernel 2.6.28.
- The **Reiser** filesystem was the first jornaling implementation in Linux.
- The **JFS** filesystem is a product of IBM.
- The **XFS** filesystem is a product of SGI.
- The **btrfs** filesystem (**B** **TR**ee filsesystem) is the most recent, is native to Linux, and has many advanced features. Default in SUSE.

## Mounting Filesystems
In UNIX-like operating systems, all files are arranged in one big filesystem tree rooted at /. Many different partitions on many diferent devices may be voalesced together by mounting partitions on various mount points, or directories in the tree.
The full form of the **mount** command is:
> $ sudo mount [-t type] [-o options] device dir

Most filesystems need to be loaded at boot and the information required to specify mount points, options, devices, etc., is specified in **/etc/fstab**

You can also mount NFS (Network File Systems) as in:
> $ sudo mount 192.168.1.100:/var/ftp/pub /mnt

## RAID and LVM
**RAID** (Redundant Array of Independent Disks) spreads I/O over multiple spindels, or disks; this can really increase performance in modern disk controller interfaces, such as SCSI which can perform the work in parallel efficiently. RAID can be implemented in Software or in hardware.
Three essential features of RAID are:
- **Mirroring**: writing the same data to more than one disk.
- **Striping**: Splitting of data to more than one disk.
- **Parity**: Extra data is stored to allow problem detection and repair, yielding fault tolerance.

Using **LVM** (Logical Volume Management) breaks up one virtual partition into multiple chunks, which can be on different physical volumes. With LVM, it becomes really easy to change the size of the logical partitions and filesystems, to ass more space rearrange things, etc.
One or more physical disk partitions, or physical volumes, are grouped together into a volume group. Then the volume group is subdivided into logical volumes which appear to the system as disk partitions and are the formatted to contain mountable filesystems.
