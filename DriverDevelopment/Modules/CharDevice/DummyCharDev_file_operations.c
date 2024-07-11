// Declaration of file operations for dummy char driver
// the struct declaration uses the standar C tagged initialization syntax.
// It makes more portable, compact, and readable.
// It implements only the most important device methods.

// This is part of the module.h macro
#define THIS_MODULE

struct file_operations dummy_fops = {
	.owner = THIS_MODULE,
	.llseek = dummy_llseek,
	.read = dummy_read,
	.write = dummy_write,
	.ioctl = dummy_ioctl,
	.open = dummy_open,
	.release = dummy_release
};
