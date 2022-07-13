#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int fd,nread,i=0,word=0,line=0,count=0;
	char byte,buf[4096];
	fd = open(argv[1],O_RDONLY);
	if (fd < 0)
	{
		perror("Open FAILS\n");
		exit(0);
	}
	while((nread = read(fd,&byte,1)) > 0)
	{
		count++;
		buf[i]=byte;
		if(buf[i]==' ')
		{
			word++;
		}
		if(buf[i]=='\n')
		{
			line++;
			word++;
		}
		i++;
	}
	printf("%d %d %d %s\n",line,word,count,argv[1]);
}

