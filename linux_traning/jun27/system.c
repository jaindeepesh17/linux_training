#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
	System(argv[1]);
}
int System(char* s)
{
	int pid,ret,status;
	pid=fork();

	if(pid==0)
	{
		printf("Hii\n");
		ret= execl("bin\sh","sh",s,(char*)NULL);
		if(ret==-1)
		perror("execl fails");
		exit(0);
	}
	else
}
