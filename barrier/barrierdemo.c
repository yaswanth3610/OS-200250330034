#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_barrier_t barri;

void * serial_t(void * arg)
{
	printf("signal: initalization started\n");
//	sleep(2);
	printf("signal: initalization completed\n");
	pthread_barrier_wait(&barri);
	printf("signal: started\n");
}
void * lcd_t(void * arg)
{
	printf("lcd: initalization started\n");
//	sleep(7);
	printf("lcd: initalization completed\n");
	pthread_barrier_wait(&barri);
	printf("lcd: started\n");
}
void * ethernet_t(void * arg)
{
	printf("ethernet: initalization started\n");
//	sleep(10);
	printf("ethernet: initalization completed\n");
	pthread_barrier_wait(&barri);
	printf("ethernet: started\n");
}
void * adc_t(void * arg)
{
	printf("adc: initalization started\n");
//	sleep(4);
	printf("adc: initalization completed\n");
	pthread_barrier_wait(&barri);
	printf("adc: started\n");
}
int main()
{
	pthread_t lcd,adc,ethernet,serial;
	pthread_barrier_init(&barri,NULL,4);
	pthread_create(&serial,NULL,serial_t,NULL);
	pthread_create(&lcd,NULL,lcd_t,NULL);
	pthread_create(&ethernet,NULL,ethernet_t,NULL);
	pthread_create(&adc,NULL,adc_t,NULL);
	pthread_join(serial,NULL);
	pthread_join(lcd,NULL);
	pthread_join(ethernet,NULL);	
	pthread_join(adc,NULL);
	pthread_barrier_destroy(&barri);
}
