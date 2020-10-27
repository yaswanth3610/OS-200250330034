#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 100

int main()
{
	int s_fd,r_fd,num[SIZE],rbuff[SIZE];
	mkfifo("desd",S_IRUSR | S_IWUSR);
	printf("enter the two numbers\n");
	scanf("%d %d",&num[0],&num[1]);
	s_fd= open ("desd",O_WRONLY);
	write(s_fd,num,SIZE);
	r_fd=open("desd",O_RDONLY);
        read(r_fd,rbuff,SIZE);
	printf("recived from reciver:%d \n",rbuff[0]);
	close(s_fd);
	return 0;
}
