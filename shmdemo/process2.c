#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int *count_process2;

int main()
{ 
	int shmfd;
	shmfd=shm_open("/cdacshm",O_RDWR | O_CREAT,S_IRUSR | S_IWUSR);
	ftruncate(shmfd,sizeof(int));
	count_process2 = (int *) mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE ,MAP_SHARED,shmfd,0);
	while(1)
	{
		printf("Count in process2 : %d\n",*count_process2);
		sleep(1);
	}
	shm_unlink("/cdacshm");
	return 0;
}
