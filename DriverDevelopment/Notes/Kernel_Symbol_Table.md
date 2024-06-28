# The kernel symbol table

The table of public kernel symbols contains the addresses of global kernel items -functions, and variables- that are needed to implement modularized drivers. When a module is loaded, any symbol exported by the module becomes part of the kernel symbol table. These symbols, other kernel modules may using them, with the option of stacking new modules on top of other modules. For example, each input USB device module stacks on the *usbcore* and *input* modules.

The Linux kernel header files provide a convinient way to manage the visibility of your symbols, thus reducing the namespace pollution and promoting proper information hiding. If your module needs to export symbols for other modules to use, the following macros should be used:

`
EXPORT_SYMBOL(name);
EXPORT SYMBOL_GPL(name);
`
