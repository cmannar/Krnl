#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/proc_fs.h> 
#include <linux/string.h>
#include <linux/vmalloc.h> 
#include <asm/uaccess.h>

#define MAX_LEN 4096
int read_info(char *page, char **start, off_t off, int count, int *eof, 
             void *data);
ssize_t write_info(struct file *filp, const char __user *buff, unsigned 
             long len, void *data);

static struct proc_dir_entry *proc_entry;
static char *info;
static int write_index; 
static int read_index;

int init_module(void) {
    int ret = 0;
    // allocated memory space for the proc entry
    info = (char *)vmalloc(MAX_LEN); 
    memset(info, 0, MAX_LEN);
    
    //implement this: create the proc entry
    
    write_index = 0;
    read_index = 0;
    
    //register the write and read callback functions 
    proc_entry->read_proc = read_info; 
    proc_entry->write_proc = write_info;
    printk(KERN_INFO "test_proc created .\n");
    return ret; 
}

void cleanup_module(void){
    //remove the proc entry and free info space
}

ssize_t write_info(struct file *filp, const char __user *buff,  
    unsigned long len, void * data){
    //copy the written data from user space and save it in info
   return len; 
}

int read_info(char *buff, char **start, off_t offset, int count, 
    int *eof, void *data){
    //output the content of info to user's buffer pointed by buff
    return len; 
}
