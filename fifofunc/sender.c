#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	mkfifo("desd",S_IRUSR | S_IWUSR);
	fd= open ("desd",O_WRONLY);
	write(fd,"cdac\n",5);
	close(fd);
	return 0;
}
