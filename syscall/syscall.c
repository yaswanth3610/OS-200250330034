 #include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open ("desd.txt",O_WRONLY | O_CREAT);

	if(fd == -1 )
	{
		perror("ERROR in Open: \n");
		return -1;
	}

	write (fd, "yaswanth",8);
	close(fd);
	return 0;
}
