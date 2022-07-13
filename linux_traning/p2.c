#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
	int ret;

	ret = write(3,"Hello world\n",12);
	printf("Ret: %d errmo:%d\n",ret,errno);
	if (ret < 0)
	{
		perror("Write fail:");
	}
	return 0;
}
