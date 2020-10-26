#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 100

int main()
{
	int fd,num[SIZE],rbuff[SIZE];
	printf("enter the two numbers\n");
	scanf("%d %d",&num[0],&num[1]);
	fd= open ("data.txt",O_RDWR);
	write(fd,num,SIZE);
	close(fd);
        read(fd,rbuff,SIZE);
	printf("recived from reciver:%d \n",rbuff[0]);
	close(fd);
	return 0;
}
