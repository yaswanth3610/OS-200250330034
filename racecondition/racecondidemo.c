#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int count = 0;

void * thread_inc(void *arg)
{
	while(1)
	{
		count++;
	    	printf("inc thread : %d\n",count);
	}
}

void * thread_dec(void *arg) 
{
        while(1)
        {       
                count--;
                printf("dec thread : %d\n",count);
        }
}

int main()
{
	pthread_t tid_inc,tid_dec;
	pthread_create(&tid_inc,NULL,thread_inc,NULL);
	pthread_create(&tid_dec,NULL,thread_dec,NULL);
	pthread_join(tid_inc,NULL);
	pthread_join(tid_dec,NULL);
	return 0;
}
