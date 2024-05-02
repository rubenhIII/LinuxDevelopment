# The Development of Shells

bash is one of the most used shell, but some of the main choices include:

- sh was written by Steve Bourne at AT&T in 1977, and is thus often known as the Bourne Shell.
- csh was written by Bill Joy at UC Berkeley and released in 1978; The internal syntax is quite different that sh and is designed to resemble that of the C programming laguage.
- tcsh was originally developed by Ken Greer at Carnegie Mellon University in the late 1970; the t stands for TENEX, an operating system that was used on some DEC PDP-10s.
- ksh was witten by David Korn at AT&T in 1982 and it was designed to be a major upgrade to sh.
- bash (Bourne Again SHell) is a product of the GNU project and was created in 1987; it was designed as a major upgrade of sh.
- zsh was created by Paul Falstad at Princenton University in 1990; it is named after a professor, Zhong Shao.

## Shell Initialization

> A user's default shell can be changed with the chsh utility.

Kind of shells:

- A login shell is one requiring a password.
- An interactive shell is one in which the standard input/output streams are connected to a terminals.
- A non-interactive shell is one in which the standard input/output stream may be connected to a process, etc.

### Initialization
- Login shells:
	- if /etc/profile exists, source it
	- if ~/.bash_profile exists, source it
	- else if ~/.bash_login exists, source it
	- else if ~/.profile exists, source it
	- on exit, if ~/.bash_logit exists, source it
- Non-login shells:
	+ if ~/.bashrc exists, source it
	
> By default, mos distributions include a system-wide file (usually **/etc/bashrc**) from the user's  **~/.bashrc**.

## Aliases
Aliases permits custom definitions. Typing **alias** with no arguments gives the list of defined aliases. **unalias** gets rid of an alias.

> $ alias hello="echo Hello World" ; hello
>> Hello World!

## Environment Variables
Environment variables are not limited in length or number. Lots of applications use them in first instance , in order to set default values for configuration options.
> **HOME**, **HOST**, **PATH** are examples of environment variables and can be set as in **PATH:PATH=$HOME/bin:$PATH** for example.

> Putting **./** in your path is a security risk; it can be substituted an executable which which could be quite harmful.

> Type **env** or **export** to get a list of presently exported environment variables, set to get the complete set of variables.

> An environment variable must be exported to propagate its value to a child process. You can do either of the following:
>> $ VAR=value ; export VAR 

>> $ export VAR=value

You can also make one or more environment variables take effect for just one command:

> $ LD_LIBRARY_PATH=$PWD DEBUG=3 ./foobar

## Redirection

File descriptors:
- 0 = stdin
- 1 = stdout
- 2 = stderr

## Special Characters
### Redirection Special Characters
- \\#> Redirect output descriptor (Default #=1, stdout)
- < Redirect input descriptor
- \>> Append output
- \>& Redirect stdout and stderr(equivalent to **..\>..2 \>&1**)

### Compound Commands Special Characters
- | Piping
- () Execute in a separate shell
- && AND list
- || OR list
- ; Separate commands

### Expansion Special Characters
- {} Lists
- ~ Usually means $HOME
- $ Parameter substitution
- 'Back tick; used in expression evaluation (also $() syntax
- $(()) Arithmetic substitution
- [] Wildcard expressions, and conditionals.

### Escapes Special Characters
- \ End of line, escape sequence
- ´'Take exactly as is
- "" Take as is, but do parameter expansion

### Other Special Characters
- & Redirection and putting task in background
- \# Used for comments
- *? Used in wildcard expression
- ! Used in history expansion

## Pipes

Each step in a pipeline is a separate shell.

> **tee** copies the standar input to each file, and to the standard output.


