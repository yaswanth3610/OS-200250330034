#include <stdio.h>
#include <unistd.h>

#define SIZE  100 

int add(int a,int b)
{
	return a+b;
}

int main()
{
	int pfd[2],pfd1[2],tbuff[SIZE],rbuff[SIZE];   

	printf("Enter two numbers : \n");
	scanf("%d %d",&tbuff[0],&tbuff[1]);

	pid_t id; //opaque data type

	pipe(pfd); //pipe pfd created
	pipe(pfd1); //pipe pfd1 created

	id=fork(); //creating child process

	if(id == 0)//child
	{
		read(pfd[0],tbuff,SIZE);          //read data from  parent by pfd pipe
		printf("child recived num1 : %d \n",tbuff[0]);
		printf("child recived num2 : %d \n",tbuff[1]);
		rbuff[0]=add(tbuff[0],tbuff[1]);
		write(pfd1[1],rbuff,SIZE);        //sending sum to parent by pfd1 pipe
		printf("child return sum: %d \n",rbuff[0]);
		close(pfd1[1]);
	}

	else    //parent
	{
		write(pfd[1],tbuff,SIZE);          //sending data to child by pfd pipe 
		printf("parent sent num1 :%d \n",tbuff[0]);
		printf("parent sent num2 :%d \n",tbuff[1]);
		close(pfd[1]);
		read(pfd1[0],rbuff,SIZE);          //read sum from child by pfd1 pipe
		printf("parent recived sum :%d \n",rbuff[0]);
	}
	return 0;
}
