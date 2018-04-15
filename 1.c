#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int num;
	A:
	{
		printf("\nEnter any positive number ");
		scanf("%d",&num);
	}
	if(num>0)
	{
		pid_t p=fork();
		if(p==0)
		{
			while(num!=0)
			{
				printf("%d",num);
			    	printf(" ");
			    	num = num/2;
			}
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		printf("Invalid Input value ");
		goto A;
        }

}