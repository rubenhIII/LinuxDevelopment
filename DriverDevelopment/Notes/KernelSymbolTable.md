# The kernel symbol table

The table of public kernel symbols contains the addresses of global kernel items -functions, and variables- that are needed to implement modularized drivers. When a module is loaded, any symbol exported by the module becomes part of the kernel symbol table. These symbols, other kernel modules may using them, with the option of stacking new modules on top of other modules. For example, each input USB device module stacks on the *usbcore* and *input* modules.

## Kernel module code requirements

The Linux kernel header files provide a convinient way to manage the visibility of your symbols, thus reducing the namespace pollution and promoting proper information hiding. If your module needs to export symbols for other modules to use, the following macros should be used:

```
EXPORT_SYMBOL(name);  
EXPORT SYMBOL_GPL(name);  
```
The \_GPL version makes the symbol available to GPL-licensed modules only. Symbols must be exported in the global part of the module's file, outside of any function, beacuse the macros expand to the declaration of a special-purpose variable that is expected to be accesible globally. This variable is stored in a special part of the module executible (an "ELF section") that is used by the kernel at load time to find the variables exported by the module.

The kernel as a unique environment, it imposes its own requirements on code that would interface with it. Most kernel code ends up including a large number of header files to get definitions of functions, data types, and variables. Thus, just about all module code has the following:

```
#include <linux/module.h>  
#include <linux/init.h>  
``` 
*module.h* contains many definitions of symbols and functions needed by loadable modules. *init.h* is needed to specify the initialization and cleanup functions. Most modules also include *moduleparam.h* to enable the parsing of parameters to the module at load time.

It is not strictly neccesary, but the module should specify which license applies to its code. Doing so is done including:
```
MODULE_LICENSE("GPL");
```
Other descriptive definitions that can be contained within a module include *MODULE_AUTHOR*, *MODULE_DESCRIPTION*, *MODULE_VERSION*, *MODULE_ALIAS*, and *MODULE_DEVICE_TABLE*, this last one to tell user space about which devices the module supports.
The various *MODULE_* declarations can appear anywhere within your source file outside a function. A convention in kernel code, is to put these declarationsath the end of the file.

## Initialization and shutdown
The module initialization function registers any functionality offered by the module. The definition of the initialization function looks like:
```
static int _ _init initialization_function(void)  
{  
    /*Initialization code here*/  
}  
module_init(initialization_function);  
```
Initialization functions should be declared ```static```, since they are not meant to be visible outside the specific file. No function is exported to the rest of the kernel unless explicity requested. The ```_ _init``` token is a hint to the kernel that the given function is used only at initialization time. The module loader drops the initialization function after the module is loaded, making its memory available for other uses. There is a similar tag (```_ _initdata```) for data used only during initialization. Use of both labels is optional.
The use of ```module_init``` is mandatory. This macro adds a special section to the module's object code stating where the module's initialization function is to be found. Without this definition, your initialization function is never called.

The arguments passed to the kernel registration functions are usually pointers to data structures describing the new facility and the name of the facility being registered. The data structure usually contains pointers to module functions, which is how functions in the module body get called.

### The Cleanup function
Every nontrivial module also requires a cleanup function, which unregisters interfaces and returns all resources to the system before the odule is removed. This function is defined as:

```
static void _ _exit cleanup_function(void)  
{  
    /* Cleanup code here */
}  
```

The cleanup function has no value to return, so it is declared ```void```. The ```_ _exit``` modifier marks the code as mbeing for module unload only. A function marked `_ _exit` can be called *only* at module unload or system shutdown time; any other use is an error. The *module_exit* declaration is neccesary to enable the kernel to find your cleanup functions.

