#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Order 0, pid: %d\n", getpid());
	sleep(1);
   	int p1=fork();
    if(!p1) printf("Order 1, pid: %d\n", getpid());
    sleep(1);
    int p2=fork();
	if(!p2) printf("Order 2, pid: %d\n", getpid());
	sleep(1);
	int p3=fork();
	if(!p3) printf("Order 3, pid: %d\n", getpid());
	sleep(1);
    return 0;
}
