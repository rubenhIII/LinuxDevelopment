Monitoring and Performance Utilities

Linux distributions come with many standar performance and profiling tools already installed. Some of them may be familiar from other UNIX-like operating systems, while others were developed specifically for Linux.
Many of these tools gather their information from the /proc pseudo-filesystem.

## Process and Load Monitoring Utilities

| Utility | Purpose | Package |
| :-----: | :-----: | :-----: |
| top | Process activity, dinamically updated. | procps |
| uptime | How long the system is running and the average load | procps|
| ps | Detailed information about processes | procps |
| pstree | A tree of processes and their connections | psmisc (or pstree) |
| mpstat | Multiple processor usage | sysstat |
| iostat | CPU utilization and I/O statistics |
| sar | Display and collect information about system activity | sysstat |
| numastat | Information about NUMA (Non-Uniform Memory Architecture) | numactl|
| strace | Information about all system calls a process makes | strace |


## Memory Monitoring Utilities
| Utility | Purpose | Package |
| :-----: | :-----: | :-----: |
| free | Brief summary of memory usage | procps |
| vmstat | Detailed virtual memory statistics annd block I/O, dynamically updated | procps |
| pmap | Process memory map | procps |

## I/O Monitoring Utilities
| Utility | Purpose | Package |
| :-----: | :-----: | :-----: |
| iostat | CPU utilization and I/O statistics | sysstat |
| iotop | I/O statistics per process | iotop |
| sar| Display and collect information about system activity | sysstat |
| vmstat | Detailed virtual memory statistics and block I/O, dynamically updated | procps |

## Network Monitoring Utilities
| Utility | Purpose | Package |
| :-----: | :-----: | :-----: |
| netstat | Detailed networking statistics | netstat |
| iptraf | Gather information on network interfaces | iptraf |
| tcpdump | Detailed analysis of network packets and traffic | tcpdump |
| wireshark | Detailed network traffic analysis | wireshark |




