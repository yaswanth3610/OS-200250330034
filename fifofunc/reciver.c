#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	unsigned char rbuff[64];
	int fd;
	mkfifo("desd",S_IRUSR | S_IWUSR);
	fd= open ("desd",O_RDONLY);
	read(fd,rbuff,64);
	printf("recived from sender:%s \n",rbuff);
	close(fd);
	return 0;
}
