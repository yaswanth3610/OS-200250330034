#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t id;
	id = fork();
	if(id==0)
	{
		printf("child starting\n");
		sleep(10);
		printf("child exiting\n");
	}
	else
	{
		printf("parent starting\n");
		sleep(1);
		printf("parent exiting\n");
	}
	return 0;
}
