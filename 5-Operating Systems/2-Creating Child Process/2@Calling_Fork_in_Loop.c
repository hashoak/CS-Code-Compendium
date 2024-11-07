#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parent(int pid)
{
	printf("I'm a Parent Process with ID %d. %d is my child.\n",getpid(),pid);
}

void child()
{
	printf("I'm a Child Process with ID %d\n",getpid());
}

void failed()
{
	printf("I'm a parent process with ID %d. My child failed.\n",getpid());
}

int main(int argc, char *argv[])
{
	for(int i=0;i<3;i++)
	{
		int p=fork();
	    if(p>0) parent(p);
	    else if(p==0) child();
	    else failed();
	    sleep(1);
	}
    return 0;
}
