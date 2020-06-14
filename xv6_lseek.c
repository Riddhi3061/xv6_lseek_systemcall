#include "types.h"
#include "defs.h"
#include "param.h"
#include "stat.h"
#include "mmu.h"
#include "proc.h"
#include "fs.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "file.h"
#include "fcntl.h"
#include "x86.h"

int sys_lseek_xv6(void){
	//int fd;
	signed int offset;
	struct file *files;
	int macro, count, fd;
	  //extra
	char *pointer;
	signed int offset1=0;
	argfd(0, &fd, &files);
	argint(1, &offset);
	argint(2, &macro);
	if(macro == 0){
		offset1 = offset;
		files->off = offset1;
	}
	else if(macro == 1){
		offset1 = files->off + offset;
		files->off = offset1;
	}
	else if(macro == 2){
		offset1 = files->ip->size + offset;
	}
	if(offset1 < files->ip->size){
		return -1;
	}
	if(offset1 > files->ip->size){
		count = offset1 - files->ip->size;
		pointer = kalloc();
		while(count > 0){
			filewrite(files, pointer, count);
			count = count - 4096;
		}
		kfree(pointer);
	}
	files->off = offset1;
	int y = files->off;

}
