# File and Text Manipulation Utilities

## cat
**cat** is short for concatenate. It is pften used to read and print files, as well as for simply viewing file contents.
The **tac** command (cat spelled backwards) prints the lines of a file in reverse order. Each line remains the same, but the order of lines is inverted.

## echo
**echo** displays (echoes) text.It can be used to display a string on standar output (i.e. terminal) or to place in a new file (using the > operator) or append to an alrady existing file (using the >> operator).
The -e option, along with the following switches, is used to enable special character sequences, such as the newline character or horizontal tab:
- \\n represtes a new line
- \\t represents horizontal tab
echo is particularly useful for viewing the values of environment variables.

## head and tail
**head** reads the first few lines of each named file (10 by default) and displays it on standar output. You can give a different number of lines using the -n option.
**tail** prints the last few lines of each file and displays it on stdout. It hast the same -n option. You can continually monitor new output in a growing file using the -f option.

## Viewing Compressed Files
There iis also version specially designed to work directly with compressed files. These associated utilties have the letter "z" prefixed to their name. For example, we have utility programs such as zcat, zless, zdiff and zgrep.
There are also equivalent utility programs for other compression methods besides gzip, for example bzcat and bzless associated with bzip2, and zxcat and xzless associated with xz.

## sed and awk
**sed** for Stream Editor is a powerful text processing tool and one of the oldesr, earliest and most UNIX utilities. It is used to modify the contents of a dile, usually placing the contents into a new file, and it can also filter text, as well as perform subsitutions in data streams.

**awk** was created at Bell Labs in the 1970 and derived its name from the last names of its author: Alfred Aho, Peter Weinberger, and Brian Kernigham. It used to extract and then print specific contents of a file and is often used to construct reports. It is used to manipulate data files, retrieving, and processing text. Works well with fields (containing a single piece of data, essentially a column) and records (a collection of fields, essentially a line in a file). The commands can be specified directly at the command line, but a more complex script can be saved that you can specify using the -f option. The command/action in awk needs to be surrounded with apostrophes and can be used as follows:

| Command | Usage |
| :-----: | :---: |
| awk '{print $0}' /etc/passwd | Print entire file |
| awk -F:'{print $1}' /etc/passwd | Print first field (column) of every line, separated by a space |
| awk -F '{print $1 $7}' /etc/passwd | Print first and seventh field of every line |

## File Manipulation Utilities
In managing your files, you may need to perform many tasks, such as sorting data and copying data from one location to another.
Linux provides several file manipulation utilities that you can use while working with text files, including:
- sort: it is used to rearrange the lines of a text file either in ascending or descending order, according to a sort key. You can also sort by particular fields of a file. The default sort key is the order of the ASCII characters. When used the -u option, sort checks for unique values after sorting the records. It is equivalent to running uniq on the output of sort.
- uniq: Removes duplicate consecutive lines in a text file and is useful for simplifying the text display. Because uniq requires that the duplicate entries must be consecutive, one often runs sort first and then pipes the output into uniq. The -c option count the number of duplicate entries.
- paste: Can be used to create a single file containing all columns of multiple files. The different columns are identified based on delimiters (spacing used to separate two fields); delimiters can be a blank space, a tab, or an Enter. paste accept -d option which specifies a list of delimiters to be used instead of tabs for separating consecutive values on a single line; each delimiter is used in turn and when the list has been exhausted, paste begins again at the firts delimiter. -s option causes paste to append the data in series rather than in parallel; thet is, in a horizontal rather than vertical fashion.
- join: It first checks wether the files share common fields, such as names or phone numbers, and then joins the lines in two files based on a common field.
- split: It is used to break up (or split) a file into equal sized segments for easier viewing and manipulation, and is generally used only in relatively large files. By default, split breaks up a file into 1000-line segments; the original file remains unchanged, and a set of new files with the same name plus an added prefix is created.





