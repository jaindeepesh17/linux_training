//own version of "getchar"-reads a single character from the standard input stream stdin

#include<stdio.h>
//for errno
#include <errno.h>
//for exit(0)
#include <stdlib.h>
//for O_RDONLY mode
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int ret;
	char buff;
	
	//reads char from keyboard
	ret=read(0,&buff,1);
	//displays it on monitor
	write(1,&buff,1);
	
	exit(0);
	return 0;
}
