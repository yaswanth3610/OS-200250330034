#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t id;
	id = fork();
	if(id==0)
	{
		printf("child starting\n");
		printf("child exiting\n");
	}
	else
	{
		printf("parent starting\n");
		sleep(10);
		printf("parent exiting\n");
	}
	return 0;
}
