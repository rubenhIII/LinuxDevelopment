> sudo apt-get install build-essential vim git cscope libncurses-dev libssl-dev bison flex
> sudo apt-get install git-email

To sen patch through evolution:
Evolution (GUI)
Some people use this successfully for patches.

When composing mail select: Preformat
from Format‣Paragraph Style‣Preformatted (CTRL-7) or the toolbar

Then use: Insert‣Text File... (ALT-N x) to insert the patch.

You can also diff -Nru old.c new.c | xclip, select Preformat, then paste with the middle button.

 
