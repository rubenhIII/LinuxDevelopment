# Introduction to Filesystems
In the UNIX tradition, all filesystems and partitions are located under the root filesystem root (/) directory.
Other partitions are generally mounted on various subdirectory points as are network file systems which may or may not be mounted at any given time.

The **Filesystem Hierarchy Standard (FHS)**, administered originally by the Free Standards Group, and now the Linux Foundation, specifies the main directories that need to be present and describes their purposes.

## Filesystem Layout

| Directory | In FHS | Purpose |
| :-------: | :----: | :-----: |
| / | Yes | Primary directory of the entire filesystem hirerarchy. |
| /bin | Yes | Essential executable programs that must be available in single user mode. |
| /boot | Yes | Files needed to boot the system, such as the kernel, initrd or initramfs images, and boot configuration files and bootloader programs. |
| /dev | Yes | **Devices Nodes**, used to interact with hardware and software devices. |
| /etc | Yes | System-wide configuration files. |
| /home | Yes | User home directories, including personal settings, files, etc. |
| /lib | Yes | Libraries requiered by executable binaries in /bin and /sbin. |
| /lib64 | No | 64-bit libraries required by executable binaries in /bin and /sbin, for systems which can run both 32-bit and 64-bit programs. |
| /media | Yes | Mount points for removable media such CD's, DVD's, USB sticks, etc. |
| /mnt | Yes |  Temporary mounted filesystems. |
| /opt | Yes | Optional application software packages. |
| /proc | Yes | Virtual pseudo-filesystem giving information about the system and processes running on it; can be used to alter system parameters. |
| /run | Yes | System information data describing the system since it was booted; should be cleared at every reboot. |
| /sys | No | Virtual pseudo-filesystem giving information about the system and processes running o it; can be used to alter system parameters, is similar to a device tree and is part ofthe Unified Device Model. |
| /root | Yes | Home directory for the root user. |
| /sbin | Yes | Essential system binaries. |
| /srv | Yes | Site-specific data served up by the system; seldom used. |
| /tmp | Yes | Temporary files; on many distributions lost across a reboot and may be a ramdisk in memory. |
| /usr | Yes | Multi-user applications, utilities and data; theoretically read-only. |
| /var | Yes | Variable data that changes during system operation. |

### Directories under /usr

|  Directory  | Purpose |
| :---------: | :-----: |
| /usr/bin | Non-essential binaries and scripts, not needed for single user mode; generally this means user applications not needed to start system. |
| /usr/include | Header files used to compile applications. |
|/usr/lib | Libraries for programs in **/usr/bin** and **/usr/sbin**. |
| /usr/sbin | Non-essential system binaries, such system daemons. | 
| /usr/share | Shared data used by applications, generally architecture-independent. |
| /usr/src | Source code; generally for the Linux kernel. |
| /usr/XR | X Window files; generally obsolete. |
| /usr/local | Local data and programs specific to the host; subdirectories include **bin**, **sbin**, **lib**, **share**, **include**, etc. |


### Directories under var
|  Directory  | Purpose |
| :---------: | :-----: |
| /var/lib | Persistent data modified by programs as they run. |
| /var/lock | Lock files used to control simultaneous access to resources. |
| /var/log | Log files. |
| /var/mail | User mailboxes. |
| /var/run | Information about the running system since the last boot. |
| /var/spool | Temporary files to be preserved across system reboot; sometimes linked to /tmp. |
| var/www | Root for website hierarchies. |