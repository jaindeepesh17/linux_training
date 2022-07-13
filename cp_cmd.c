#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
	char block[1024]; 
    	int in, out; 
	int nread;
	if(argc!=3)
        {
                 fprintf(stderr, "Usage: %s <source_file_name> <dest_file_name>\n", argv[0]);
                 exit(EXIT_FAILURE);
        }
	in = open(argv[1], O_RDONLY);
	if (in < 0)
	{
		perror("Open FAILS\n");
		exit(0);
	} 
        out = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

	while((nread = read(in,block,sizeof(block))) > 0)
	{
        	write(out,block,nread);
	}
}
