#include "fcntl.h"
#include "syscall.h"
#include "x86.h"
#include "types.h"
#include "stat.h"
#include "user.h"

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int main(int argc, char *argv[]){
	char text[1024];
	int fd, off, var;
	unsigned int length;
	if(argc !=5){
		exit();	
	}
	fd = open(argv[1], 0);
	if(fd == -1){
		printf(0, "%s", "FILE OPEN: Failed");
		exit();
		
	}
	off = atoi(argv[2]);
	length = atoi(argv[3]);
	lseek(fd, off, SEEK_SET);
	var = read(fd, text, len);
	if(var == -1){
		printf(0, "%s", "Read from file could not happen\n");
		exit();
	}
	if(!strcmp(argv[4], text)){
		printf(0, "%s", "Given String:");
		printf(0, "%s", argv[4]);
		printf(0, "%s", "\nString read from given file:");
		printf(0, "%s", text);
		printf(0, "%s", "\nSuccess");
	}
	else {
		printf(0, "%s", "Given String:");
		printf(0, "%s", argv[4]);
		printf(0, "%s", "\nString read from file:");
		printf(0, "%s", text);
		printf(0, "%s", "\nNot Same");
	}
	close(fd);
	exit();
	return 0;

}

