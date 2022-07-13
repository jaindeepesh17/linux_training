#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int fd,nread;

	char buf[100];

	fd = open(argv[1],O_RDONLY);
	if (fd < 0)
	{
		perror("Open FAILS\n");
		exit(0);
	}
	while((nread = read(fd,buf,sizeof(buf))) > 0)
        write(1,buf,nread);
}
