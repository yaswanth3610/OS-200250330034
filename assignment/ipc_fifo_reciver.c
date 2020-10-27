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
	int tbuff[SIZE],num[SIZE];
	int s_fd,r_fd;
	s_fd= open ("desd",O_RDONLY);
	read(s_fd,tbuff,SIZE);
	printf("recived from sender:%d %d \n",tbuff[0],tbuff[1]);
        num[0]=add(tbuff[0],tbuff[1]); 
	printf("sum:%d\n",num[0]);
//	mkfifo("desd1",S_IRUSR | S_IWUSR);
	r_fd=open("desd",O_WRONLY);
        write(r_fd,num,SIZE);	
	close(r_fd);
	return 0;
}
