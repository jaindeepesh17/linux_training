#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
	FILE* fp;
	char ch,arr[50];
	int count=0,size=0,line=0,ret;
	if(argc!=2)
	{
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
                exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1],"r");
	if(fp==NULL)
	{
		perror("Open FAILS\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=-1)
	{
		size++;
		if(ch=='\n')
		{
			line++;
		}
	}
	rewind(fp);
	while((ret=fscanf(fp,"%s",arr))!=-1)
	{
		count++;
	}
	printf("%d %d %d %s\n",line,count,size,argv[1]);
}
