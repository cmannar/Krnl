#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/init.h>

//changing the names cause with origional names it gave re-definition error, cause already defined in init header

int init_module1(void) {
    printk (KERN_INFO "Hello world!\n");
    return 0; 
}

void cleanup_module1(void){ 
    printk (KERN_INFO "Goodbye world!\n");
} 

module_init(init_module1); // Need include init to work 
module_exit(cleanup_module1); /* Need include init to work 
(returns resources back to kernel instead of leaving it hanging, so don't overflow memory)*/

MODULE_LICENSE("GPL");
