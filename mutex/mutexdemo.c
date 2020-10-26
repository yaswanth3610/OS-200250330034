#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int count = 0;
pthread_mutex_t count_mutex;
void * thread_inc(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&count_mutex);
		count++;
	    	printf("inc thread : %d\n",count);
		pthread_mutex_unlock(&count_mutex);
	}
}

void * thread_dec(void *arg) 
{
        while(1)
        {
	        pthread_mutex_lock(&count_mutex);	
                count--;
                printf("dec thread : %d\n",count);
		pthread_mutex_unlock(&count_mutex);
        }
}

int main()
{
	pthread_t tid_inc,tid_dec;
	pthread_mutex_init(&count_mutex,NULL);
	pthread_create(&tid_inc,NULL,thread_inc,NULL);
	pthread_create(&tid_dec,NULL,thread_dec,NULL);
	pthread_join(tid_inc,NULL);
	pthread_join(tid_dec,NULL);
	pthread_mutex_destroy(&count_mutex);
	return 0;
}
