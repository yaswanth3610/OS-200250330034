#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int count =0;

int main()
{
	pid_t id;

	printf("Before fork \n");

	id = fork();

	if (id == 0)
	{
//		printf("In child: PID = %d \t PPID =%d \n",getpid(),getppid());
		printf("count in chaild =%d",count);

	}
	else
	{
		count++;
//		printf("In parent: PID =%d \t PPID =%d \n",getpid(),getppid());
		printf("count in parent =%d",count);
	}

//	printf("After fork id \t PID\t PPID: %d %d %d \n",id,getpid(),getppid());
	return 0;
}

