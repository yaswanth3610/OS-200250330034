#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 100

int add(int a,int b)
{
	return a+b;
}

int main()
{
	int  tbuff[SIZE],num[SIZE];
	int fd;
	fd= open ("data",O_RDWR);
	read(fd,tbuff,SIZE);
	printf("recived from sender:%d %d \n",tbuff[0],tbuff[1]);
        num[0]=add(tbuff[0],tbuff[1]); 
        write(fd,num,SIZE);	
	close(fd);
	return 0;
}
