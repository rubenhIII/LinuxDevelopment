#!/bin/sh

# Script to load module with major number allocated dynamically.
# Based on the example in book Linux Device Drivers 3ed.

module="DummyCharDev"
device="DummyCharDev"
mode="664"

# Invoke insmod with all arguments we got
# and use a pathname, as newer modutils do not look in . by default
/sbin/insmod ./$module.ko $* || exit 1

# Remove stale nodes
rm -f /dev/"$device"[0-3]

major=$(awk -v module="$module" '$2 == module { print $1 }' /proc/devices)
echo "The major number assigned was ${major}"

mknod /dev/"$device"0 c $major 0
mknod /dev/"$device"1 c $major 1
mknod /dev/"$device"2 c $major 2

# Give appropiate group/permissions, and change the group.
# Not all distributions have staff, some have "wheel" instead.
group="staff"
grep -q '^staff:' /etc/group || group="wheel"

chgrp $group /dev/${device}[0-3]
chmod $mode /dev/${device}[0-3]




