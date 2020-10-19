#include <stdio.h>
#include <unistd.h>

int main()
{
	int pfd[2];
	pid_t id;
	unsigned char rbuff[128];
	pipe(pfd);
	id=fork();

	if(id == 0)
	{
		read(pfd[0],rbuff,128);
		printf("child : %s \n",rbuff);
	}

	else
	{
		write(pfd[1],"cdac\n",5);
		close(pfd[1]);
	}
	return 0;
}
