# System Boot
Virtually all x86-based physical Linux systems outside the embedded sphere) today use **GRUB (GRand Unified Bootloader)** to handle the early phases of system startup.
Other platforms may have other equivalents, such:
- ELILO used on IA64 (Itanium), and
- Das U-Boot used on many embedded configurations.

Some important features of GRUB are:
- Alternative operating systems can be chosen at boot time.
- Alternative kernels and/or initial ramdisks can be chosen at boot time for a given operating system.
- Boot parameters can be easily changed at boot time without having to edit configuration files in advance.

In GRUB 2 the basic configuration file is **/boot/grub/grub.cfg** or **/boot/grub2/grub.cfg**. This file os autogenerated whe you run update-grub or grub2-mkconfig (depending on distribution), based on files in the **/etc/grub.d** and **/etc/default/grub**; IT SHOULD NOT BE EDITED BY HAND.

On some purely EFI systems, this file might be found in a directory like **/boot/efi/EFI/redhat/grub.cfg**. The essential configuration file contains some global information, and then a stanza for each operating system or kernel configured.

## Boot

On x86 systems, boot begins with the BIOS identifying and initializing all system and attached peripheral devices. If permitted by BIOS settings, the system can then boot off a peripheral device such as a CD, DVD, floppy, or USB, or through network PXE; more likely it will boot off the configured hard disk.
The **MBR (Master Boot Record)** contains both the *partition table* and the *bootloader*, a short program that is responsible for loading the operating system, and thus has to have at least sufficient smarts to locate and load the kernel from disk.
This kernel can have anny name; usually on Linux systems it is called something like **vlinuz-4.18.0** which includes the kernel version number.
- The z in vlinuz indicates the kernel is compressed; it self-decompresses upon loading.
- In most circumstances, it is placed in the **/boot** directory which is often on its own partition.

### /boot directory

There might be multiple possible kernels to boot into, each of which has four files associated with it:
- **vmlinuz** is the compressed kernel.
- **initramfs** contains a complete initial root filesystem which is loaded as a ramdisk, as well as some essential kernel modules (generally, device drivers) and the programs needed to load them, that are required to load the real filesystem, at which point it is discarded.
- **config** contains all the details about how the kernel was compiled; it is not needed for system operation.
- **System.map** lists the complete kernel symbol table; it is used for debugging purposes.

> Depending on qhich Linux distribution is beig used, there will be variations. For examplem the *initiramfs* file may actually be called *initrd*.

## System Initialization

### init
**/sbin/init** (usually just called **init** is the first user-level process (or task) that runs on the system and continues to run until the system is shutdown.
Traditionally, it has been considered the parent of all user processes, although technically that is not true as some processes are started directly by the kernel. *init* coordinates the later stages of the boot process, configures all aspects of the environment and starts the processes needed for logging into the system; it also works closely with the kernel in cleaning up after processes when they terminate.

### SysViniti
Traditionally, nearly all distrinutions based the init process on UNIX's venerable **SysVinit**. This scheme was developed decades ago under rather different circumstances:
- The target was multi-user mainframe systems.
- The target was a single processor system.
- Startup (and shutdown) time was not important matter; it was far less important than getting things right.
-- Startup was viewed as a serial process, divided into a series of sequential stages; each stage requiered completion before the next could proceed, so it did not easily take advantage of the parallel processing that could be done on multiple processors or cores.
-- Shutdown/reboot was seen as a relatively rare event and exactly how long it took was not considered important.

### New Methods of Controlling System Startup
To deal with these intrinsic limitations in SysVinit, new methods of controlling system startup were developed and have replaced it in all new systems. Two main schemes were adopted by Linux distributors:
- **Upstart**
-- Developed by Ubuntu and first included in the 6.10 release in 2006, and made the default in 9.10 release in 2009.
-- Adopted in Fedora 9 (in 2008) and in RHEL 6 and its clones, such as CentOS, Scientific Linux and Oracle Linux, and in openSUSE it was offered as an option since version 11.3.
-- It has also been used in various embedded and mobile devices.
- **systemd** is more recent and Fedora was the first major distributor to adopt it in 2011.
-- RHEL 7 was based on **systemd** and since then every other major Linux distribution has adopted it and has made it the default; even Ubuntu phased out Upstart and is now systemd based.
-- Compatibility wrappers ensure one can use SysVinit utilities and methods for quite some time.
> **systemctl** is a systemd command used for controlling system services: starting and stopping, enabling and disabling at boot, showing status, etc.
