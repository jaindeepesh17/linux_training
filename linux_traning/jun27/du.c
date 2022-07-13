//du command using stat system call
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include <fcntl.h>

int main()
{
	int ret,fd,start=0,end=4095,i=1;
	struct stat temp;

	fd = open("/home/jsrirangam/Desktop/c in depth.pdf",O_RDONLY);
	ret = fstat(fd,&temp);

	if (ret == -1)
		perror("stat Fails:");

	printf("size of the file :%ld\n",temp.st_size);
	while(1)
	{
		if(temp.st_size<end && temp.st_size>start)
		{
			printf("file requires %d pages in disk",i);
			break;
		}
		else
		{
		start=start+4096;
		end=end+4096;
		i++;
		}
	}

return 0;
}
