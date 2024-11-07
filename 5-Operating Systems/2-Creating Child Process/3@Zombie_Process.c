#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   	int p=fork();
    if(p>0)
    {
		printf("I'm a Parent Process %d. %d is my child.\n",getpid(),p);
		printf("I'm going into sleep for 10 secs.\n");
		sleep(10);
		printf("I'm out from sleep after 10 secs.\n");
	}
    else
    {
    	printf("I'm a Child Process %d. I completed my execution.\n",getpid());
        exit(0);
    }
    return 0;
}
