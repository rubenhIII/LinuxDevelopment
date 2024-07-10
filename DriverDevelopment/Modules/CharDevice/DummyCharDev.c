// Example of driver registation

#define DEV_MAJOR 0
#define DEV_MINOR 0

#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");

static int dummy_major = DEV_MAJOR;
static int dummy_minor = DEV_MINOR;
static int dummy_nr_devs = 3;
static dev_t dev;

module_param(dummy_major, int, S_IRUGO);

static int dummy_init(void)
{
	static int result = 0;

	if (dummy_major){
		dev = MKDEV(dummy_major, dummy_minor);
		result = register_chrdev_region(dev, dummy_nr_devs, "dummyCharDev");
	} else{
		result = alloc_chrdev_region(&dev, dummy_minor, dummy_nr_devs, "dummyCharDev");
		dummy_major = MAJOR(dev);
	}
	if (result < 0){
		printk(KERN_WARNING "DummyCharDevice: cannot get major %d\n", dummy_major);
		return result;
	}
	printk(KERN_ALERT "Dummy driver for char device loaded\n");
	return 0;

}

static void dummy_exit(void)
{
	unregister_chrdev_region(dev, dummy_nr_devs);
	printk(KERN_ALERT "Good Bye!!!\n");
}

module_init(dummy_init);
module_exit(dummy_exit);




