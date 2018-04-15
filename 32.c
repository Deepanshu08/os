#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int ch;
	A:
	{
		printf("\nPress 1 to create two zombie process ");
        printf("\nPress 2 to create two orphan process ");
        printf("\nPress 3 to exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
	}
	while(ch==1)
	{
		pid_t p=fork();
		if(p==0)
		{
			printf("Child created \n");
			printf("Id of parent process is %d\n",getpid());
			exit(0);
		}
		else
		{
			printf("Id of process is %d\n",getpid());
			sleep(2);
		}
		printf("First Zombie Process created\n");

		pid_t p1=fork();
		if(p1==0)
		{
			printf("Child created \n");
			printf("Id of parent process is %d\n",getpid());
			exit(0);
		}
		else
		{
			printf("Id of process is %d\n",getpid());
			sleep(2);
		}
		printf("Seconnd Zombie Process created\n");
		goto A;
	}
	while(ch==2)
	{
		pid_t p2=fork();
		if(p2==0)
		{
			sleep(30);
		}
		else
		{
			printf("Parent created\n");
		}
		printf("First orphan process created\n ");

		pid_t p3=fork();
		if(p3==0)
		{
			sleep(30);
		}
		else
		{
			printf("Parent created\n");
		}
		printf("Second orphan process created\n ");
		goto A;
	}
	while(ch==3)
	{
		return 0;
	}
	while(ch!=1|ch!=2|ch!=3)
	{
		printf("Wrong choice\n");
		goto A;
	}

}