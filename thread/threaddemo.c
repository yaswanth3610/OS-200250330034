#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * thread(void *arg)
{
	printf("i created thread\n");
}

int main()
{
	pthread_t tid;
	printf("Before thread creation\n");
	pthread_create(&tid,NULL,thread,NULL);
	sleep(1);
	return 0;
}
