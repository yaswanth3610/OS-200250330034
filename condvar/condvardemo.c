#include <stdio.h>
#include <pthread.h>
int flag;
pthread_mutex_t m1;
pthread_cond_t cv1;
void * thread1(void *arg)
{
	printf("T1:Grabbing Mutex\n");
	pthread_mutex_lock(&m1);
	printf("T1:Before BL\n");
	while(flag == 0)
	{
		printf("T1:Entering conditional wait\n");
		pthread_cond_wait(&cv1,&m1);
		printf("T1:Exiting conditional wait\n");
	}
	printf("T2:After BL\n");
	pthread_mutex_unlock(&m1);
	printf("T1:Relising mutex\n");
}
void * thread2(void *arg)
{
	printf("T2:Grabbing mutex\n");
	pthread_mutex_lock(&m1);
	printf("T2:Before setting flag\n");
	flag=1;
	printf("T2:After setting flag\n");
	pthread_mutex_unlock(&m1);
	printf("T2:Relising mutex\n");
	pthread_cond_signal(&cv1);
	printf("T2:Signaling the conditonal variable\n");
}
int main()
{
	pthread_mutex_init(&m1,NULL);
	pthread_t t1,t2;
	pthread_cond_init(&cv1,NULL);
	pthread_create(&t1,NULL,thread1,NULL);
	pthread_create(&t2,NULL,thread2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&m1);
	return 0;
}

