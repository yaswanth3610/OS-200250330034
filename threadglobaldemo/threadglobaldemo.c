#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count=0;

int add(int a,int b)
{
	return a+b;
}

void * thread(void *arg)
{
	add(10,20);
	count++;
	printf("i created thread\n");
}

int main()
{
	pthread_t tid;
	int data=add(40,50);
	count++;
	printf("Before thread creation\n");
	pthread_create(&tid,NULL,thread,NULL);
	printf("Data %d\n",data);
	return 0;
}
