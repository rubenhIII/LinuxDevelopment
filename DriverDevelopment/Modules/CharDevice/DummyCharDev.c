// Example of driver registation

#define DEV_MAJOR 0
#define DEV_MINOR 0

#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>

MODULE_LICENSE("Dual BSD/GPL");

static int dummy_major = DEV_MAJOR;
static int dummy_minor = DEV_MINOR;
static int dummy_nr_devs = 3;
static dev_t dev;
struct cdev *my_cdev; 

static loff_t mllseek(struct file*, loff_t, int);
static ssize_t mread(struct file*, char __user*, size_t, loff_t*);
static ssize_t mwrite(struct file*, const char __user*, size_t, loff_t*);
//static int mioctl(struct inode*, struct file*, unsigned int, unsigned long);
static int mopen(struct inode*, struct file*);
static int mrelease(struct inode*, struct file*);

module_param(dummy_major, int, S_IRUGO);

static struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.llseek = mllseek,
	.read = mread,
	.write = mwrite,
	//.ioctl = mioctl,
	.open = mopen,
	.release = mrelease,
};

static int dummy_init(void)
{
	static int result = 0;
	int err;

	if (dummy_major){
		dev = MKDEV(dummy_major, dummy_minor);
		result = register_chrdev_region(dev, dummy_nr_devs, "DummyCharDev");
	} else{
		result = alloc_chrdev_region(&dev, dummy_minor, dummy_nr_devs, "DummyCharDev");
		dummy_major = MAJOR(dev);
	}
	if (result < 0){
		printk(KERN_WARNING "DummyCharDevice: cannot get major %d\n", dummy_major);
		return result;
	}

	my_cdev = cdev_alloc();
	my_cdev->ops = &my_fops;
	err = cdev_add(my_cdev, dev, dummy_nr_devs);
	if(err)
		printk(KERN_NOTICE "Error %d adding \n", err);

	printk(KERN_ALERT "Dummy driver for char device loaded\n");
	return 0;

}

static void dummy_exit(void)
{
	cdev_del(my_cdev);
	unregister_chrdev_region(dev, dummy_nr_devs);
	printk(KERN_ALERT "Good Bye Dummy!!!\n");
}

static loff_t mllseek(struct file*, loff_t, int)
{
	loff_t t = 0;
	return t;
}
static ssize_t mread(struct file*, char __user*, size_t, loff_t*)
{
	ssize_t size = 0;
	return size;
}
static ssize_t mwrite(struct file*, const char __user*, size_t, loff_t*)
{
	ssize_t size = 0;
	return size;
}
static int mopen(struct inode*, struct file*)
{
	int fs = 0;
	return fs;
}
static int mrelease(struct inode*, struct file*)
{
	int fs = 0;
	return fs;
}

module_init(dummy_init);
module_exit(dummy_exit);




