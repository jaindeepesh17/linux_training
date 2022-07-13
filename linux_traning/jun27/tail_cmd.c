
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc , char* argv[])
{
	char buf[1024],byte;
	int f1,i=0,n=0,nread,count=0;
	if(argc!=2)
	{
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	f1 = open(argv[1] ,O_RDONLY);
	if (f1 < 0)
	{
		perror("Open FAILS\n");
		exit(0);
	}
	while((nread = read(f1,&byte,1)) > 0)
	{
		if(byte=='\n')
		{
			n++;
		}
	}
	lseek(f1,0,SEEK_SET);
	n=n-11;
	if(n>0)
	{
		while((nread = read(f1,&byte,1)) > 0)
		{
			if(count>=n)
			{
				write(1,&byte,nread);
			}
			if(byte == '\n')
			{
				count++;
			}
		}
	}
	else
	{
		while((nread=read(f1,&byte,1))>0);
		{
			write(1,&byte,nread);
		}
	}
	close(f1);
}
