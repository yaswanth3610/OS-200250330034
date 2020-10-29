#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count=0;
pthread_rwlock_t count_rwlock;

void * thread1(void *args)
{
	pthread_rwlock_wrlock(&count_rwlock);
	count++;
	pthread_rwlock_unlock(&count_rwlock);
}
void* thread2(void *args)
{
	printf("T2:created\n");
	pthread_rwlock_rdlock(&count_rwlock);
	printf("T2:count:%d\n",count);
	pthread_rwlock_unlock(&count_rwlock);
	printf("T2:done\n");

}
void* thread3(void *args)
{
	printf("T3:created\n");
	pthread_rwlock_rdlock(&count_rwlock);
        printf("T3:count:%d\n",count);
	pthread_rwlock_unlock(&count_rwlock);
	printf("T3:done\n");

}
void* thread4(void *args)
{
	printf("T4:created\n");
 	pthread_rwlock_rdlock(&count_rwlock);
        printf("T4:count:%d\n",count);
	pthread_rwlock_unlock(&count_rwlock);
	printf("T4:done\n");

}

int main()
{
	pthread_t td1,td2,td3,td4;
	pthread_rwlock_init(&count_rwlock,NULL);
	pthread_create(&td1,NULL,thread1,NULL);
	pthread_create(&td2,NULL,thread2,NULL);
	pthread_create(&td3,NULL,thread3,NULL);
	pthread_create(&td4,NULL,thread4,NULL);
	pthread_rwlock_destroy(&count_rwlock);
	pthread_join(td1,NULL);
	pthread_join(td2,NULL);
	pthread_join(td3,NULL);
	pthread_join(td4,NULL);
	return 0;
}

