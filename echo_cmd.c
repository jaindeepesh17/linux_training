#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char*argv[])
{
	int i,j,k=0,count=0;
	char buf[100];
//	fd=open("/home/im-rt-lp-1134/linux_traning/jun27/echo_cmd.c",O_RDONLY);
	for(i=1;i<argc;i++)
	{
		for(j=0;argv[i][j];j++,k++)
		{
			buf[k]=argv[i][j];
			count++;
		}
		buf[k]=' ';
		k++;
		count++;
	}
		buf[k]='\0';
	write(1,buf,count);
}
