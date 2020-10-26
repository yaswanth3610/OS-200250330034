#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

sem_t count_sem;
int count = 0;
void * thread_inc(void *arg)
{
	while(1)
	{
		sem_wait(&count_sem);
		count++;
	    	printf("inc thread : %d\n",count);
		sem_post(&count_sem);
	}
}

void * thread_dec(void *arg) 
{
        while(1)
        {       
		sem_wait(&count_sem);
                count--;
                printf("dec thread : %d\n",count);
		sem_post(&count_sem);
        }
}

int main()
{
	pthread_t tid_inc,tid_dec;
	sem_init(&count_sem,0,1);
	pthread_create(&tid_inc,NULL,thread_inc,NULL);
	pthread_create(&tid_dec,NULL,thread_dec,NULL);
	pthread_join(tid_inc,NULL);
	pthread_join(tid_dec,NULL);
	sem_destroy(&count_sem);
	return 0;
}
