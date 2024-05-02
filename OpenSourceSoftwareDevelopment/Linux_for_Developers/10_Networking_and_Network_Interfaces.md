# Networking and Network Interfaces

The vast majority of network programming in Linux is done using the socket interface. Thus, standards-compliant programs should require little massage to work properly with Linux.
> Linux offers the **netlink** interface, which permits opening up socket connections between kernel sub-systems and applications (or other kernel sub-systems). This has been effectively deployed to implement firewall and routing applications.

> Basic information about active network interfaces on your system is gathered through both the **ip** utility, or the orlder **ifconfig** program.

To bring a network connection up and assign a static address and a DHCP client:
> $ sudo ifconfig eth0 up 192.168.1.100  
> $ sudo dhclient eth0

While **ifconfig** has been used reliably for many years, the i utility is newer (and far more versatile). It is more efficient because it uses netlink sockes, rather ioctl system calls.
The basic syntax for ip command is:
> $ ip [ OPTIONS ] OBJECT { COMMAND | help }

> $ ip link
>> Show information for all network interfaces.

> $ ip -s link show eth0
>> Show information for the eth0 network interface

> $ sudo ip addr add 192.168.1.7 dev eth0
>> Set ip address for eth0.

> $ sudo ip link set eth0 down
>> Bring eth0 down

> $ sudo ip route add 172.16.1.0/24 via 192.168.1.5 
>> Set networking route.

## Predictable Network Interface Device Names
The Predictable Network Interface Device Names scheme is trongly correlated with the use of udev and integration with systemd.
There are now 5 types of names that devices can be given:
- Incorporating Firmware or BIOS provided index numbers for on-board devices, e.g. eno1.
- Incorporating Firmware or BIOS provided PCI Express hotplug slot index numbers, e.g. ens1.
- Incorporating physical an/or geographical location of the hardware connection, e.g. enp2s0.
- Incorporating the MAC address, e.g. enx7837d1ea46da 
- Using the old classic method, e.g. eth0

On a machine with two onboard PCI network interfaces that would have been eth0 and eth1 in the older naming system:
> $ ip -s -o -a | grep eno
>> eno1 ...
>> eno2 ...


