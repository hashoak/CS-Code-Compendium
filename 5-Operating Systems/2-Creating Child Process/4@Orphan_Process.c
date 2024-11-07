#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   	int p=fork();
    if(p>0)
    {
		printf("I'm a Parent Process %d. %d is my child.\n",getpid(),p);
		printf("Parent Process completed execution.\n",getpid(),p);
		exit(0);
	}
    else
    {
    	printf("I'm a Child Process %d.\n",getpid());
    	printf("Child Process going into sleep for 10 secs.\n");
		sleep(10);
		printf("Child Process out from sleep after 10 secs. Completed my execution.\n");
        exit(0);
    }
    return 0;
}
