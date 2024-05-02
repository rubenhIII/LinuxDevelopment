# Managing System Services

Every operating system has services which are usually started on system initialization and often remain running until shutdown. Such services may be started, stopped, or restarted at any time.
All relatively new Linux distribution have adopted the systemd method. All service management is done with the **systemctl** utility.

> $ systemctl list-units -t service --all  
>> Show all available services
