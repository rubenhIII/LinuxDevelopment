# Users and Groups

All Linux users are assigned a unique user ID, which is just an integer, as well as one or more group IDs (one of which is the default one and is the same as the user ID).
the normal prescription is that normal users start with a user ID of 1000 and then go up from there.
These numbers are associated with more convinient strings, or names, through the files /etc/passwd abd /etc/group.

## etc/passwd
The file contains some important pieces of information, separated by colons:
- Account name: The name of the user on the system, which should not contain capital letters.
- Password (**x**): This can be an encrypted password, an asterisk, or an x depending on hoe securty is set up on the system.
- User ID: The numerical value for the User ID.
- Group ID: The numerical value for the primary Group ID.
- Full user name.
- Directory.
- Default Shell.

almost all entries in /etc/passwd do not correspond to real users in the normal sense, but are special entities used for certain system utilities and functions.

## Adding and removing Users and Groups
*Groups* are used to establish a set of users who have common interests for the purposes of access rights, privileges, and security considerations. Access rights to diles (and devices) are granted on the basis of the user and the group it belongs to.
Adding a new user is done with **useradd** and removing an existing user is done with **userdel**. In the simplest form:
> $ sudo useradd *username*

By default, sets the home directory to **/home/*username***, ppulates it with some basic files (copied from **/etc/skel**), adds a line to **/etc/passwd** and sets the default shell to /bin/bash.
Additional options can be specified to change these properties, and to set others, such as the user name, etc. Before the account can be used, a password must be set. This can be done with the -p option to useradd, or by doing:
> $ sudo passwd *username*
which will then prompt for adding a password.

Removing the account can be done with **userdel**. To remove the home directory while removing the account, you need to use the **-r** option.
You can change the user's characteristics after the account has been established with **usermod**. For example, you could use the **-d** option to change the home directory, or **-p** option to change the password.

Adding a new group is done with **groupadd** and it could be deleted with **groupdel**. Adding a user to a existing group can be done with:
> $ sudo usermod -aG *group* *user*
The **groupmod** utility can be used to change the group's properties, most often the numerical Group ID with the **-g** option, or its name with the **-m** option.
To removing a user from a group, a complete list of the groups must be given to the **usermod** with the **-G** option.
 
