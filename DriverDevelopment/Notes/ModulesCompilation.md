# Module compilation

The Linux headers must be installed in the host, and according the kernel to develop in. The headers can be installed as:

> $ sudo apt install linux-headers-$(uname -r)

The Linux has its own build system for external modules based on *make*, which generate the correct gcc options for a successful compilation of kernel components and modules. A basic template of the Makefile for an external module is:

## Makefile

obj-m := foo.o  

KDIR := /lib/modules/$(shell uname -r)/build  

all:  
	make -C $(KDIR) M=$(PWD) modules  
clean:  
	make -C $(KDIR) M=$(PWD) clean  

