#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>


int main()
{
	char buff[128];
	int p;
	struct mq_attr cdacmq_attr;
	mqd_t mqfd;
	cdacmq_attr.mq_flags = 0;
	cdacmq_attr.mq_maxmsg = 4;
	cdacmq_attr.mq_msgsize =128;
	cdacmq_attr.mq_curmsgs = 0;

	mqfd=mq_open("/cdacmq",O_RDONLY | O_CREAT,S_IRUSR | S_IWUSR,&cdacmq_attr);
	mq_receive(mqfd,buff,128,&p);
	printf("Received : %s\n",buff);
	mq_close(mqfd);
	return 0;
}

