#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc , char* argv[])
{
	char buf[1024],byte;
	int f1,i=0,n=0,nread;
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
		buf[i]=byte;
		if(buf[i]=='\n')
		{
			n++;
		}
		if(n==10)
		{
			write(1,buf,i);
			break;
		}
		i++;
	}
}
