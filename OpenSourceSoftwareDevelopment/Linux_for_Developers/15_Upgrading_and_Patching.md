# Upgrading and Patching

The following table lists the basic packaging operations and their **rpm** and **deb**-based equivalents.

| **Operation** | **RPM** | **deb** |
| :-----------: | :-----: | :-----: |
| Install a package | rpm -i foo.rpm | dpkg --install foo.deb |
| Install a pckage with dependencies from repository | dnf install foo | apt-get install foo |
| Remove package | rpm -e foo.rpm | dpkg --remove foo.deb |
| Remove a package and dependencies using a repository | dnf remove foo | apt remove fo
| Update package to a newer version | rpm -U foo.rpm | dpkg --install foo.deb |
| Update package using repository and resolving dependencies | dnf update foo | apt upgrade foo |
| Update entire system | dnf update | apt dist-upgrade |
| Show all installed packages | rpm -qa | dpkg --list |
| Get information about an installed package including files | rpm -qil foo | dpkg --listfiles foo |
| Show available packages with "foo" in name | dnf list foo | apt-cache search foo |
| Show all available packages | dnf list | apt-cahce dumpavail foo |
| What package does a file belong to? | rpm -qf file | dpkg --search file |
