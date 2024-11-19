#include <stdio.h>
#include <stdlib.h>

int bufferSize;
int *buffer;
int bufferIndex=0;
int x=0;

int empty;
int full; 

void wait(int *S)
{
	*S--;
	return;
}

void signal(int *S)
{
	*S++;
	return;
}

void producer()
{
	wait(&empty);
	printf("~%d\n",bufferIndex);
	buffer[bufferIndex]=x;
	printf("Produced: %d\n",x);
	bufferIndex=(bufferIndex+1)%bufferSize;
	signal(&full);
	x++;
}

void consumer()
{
	printf("~%d\n",bufferIndex);
	wait(&full);
	bufferIndex=(bufferIndex-1+bufferSize)%bufferSize;
	printf("Consumed: %d\n",buffer[bufferIndex]);
	signal(&empty);
}

int main()
{
	int n;
	printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: 
				if(empty!=0) producer();
            	else printf("Buffer is full!!");
            	break;
            case 2:
				if(full!=0) consumer();
				else printf("Buffer is empty!!");
				break;
            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}
