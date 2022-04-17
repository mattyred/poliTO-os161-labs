#include <types.h>
#include <lib.h>
#include <syscall.h>
#include <thread.h>
#include <proc.h>
#include <addrspace.h>
/*
* Implementation of syscall writes that follows the standard prototype
*/
ssize_t sys_write(int fd, const void* buf, size_t count){
    size_t i;
    char * charbuf = (char *)buf;
    for(i=0;i<count;i++){
        putch(charbuf[i]);
    }
    return (ssize_t)fd; // i return fd just to use it once
}

ssize_t sys_read(int fd, const void * buf, size_t count){
    size_t i;
    char * charbuf = (char *)buf;
    for(i=0;i<count;i++){
        charbuf[i] = (char)getch();
    }
    return (ssize_t)fd; // i return fd just to use it once
}

void sys_exit(int status){
    struct addrspace * as;
    if(status==0){
        as = proc_getas();
        as_destroy(as);
        thread_exit();
    } 
}