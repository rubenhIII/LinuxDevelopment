# Logging Files

System log files are essential for monitoring and troubleshooting. In Linux, these messages appear in various files under **/var/log**.
Ultimate control of how messages are dealt with is controlled by **syslogd** daemon (usually **rsyslogd** on modern systems) common to many UNIX-like operating systems. The newer systemd-based systems can use **journalctl** instead, but usually retain **syslogd** and cooperate with it.

In order to keep log files from growing without bound, tje **logrotate** program is run periodically and keeps four previous copies (by default) of the log files (optionally compressed) and is controlled by **/etc/logrotate.conf**.
Some of the important log files found under /var/log are:

| **File** | **Purpose** |
| :------: | :---------: |
| boot.log | System boot messages |
| dmesg | Kernel messages saved after boot. To see current contents of the kernel message buffer, type dmesg |
| messages or syslog | All important system messages |
| secure | Security related messages |
