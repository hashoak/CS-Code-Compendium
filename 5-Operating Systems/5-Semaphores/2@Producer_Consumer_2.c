#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Produce\n2.Consumer\n3.exit");
    while(1)
    {
        printf("\nenter the choice");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            if((mutex==1)&&empty!=0)
            {
                producer();
            }
            else{
                printf("buffer is full");
            }
            break;
            case 2:
            if((mutex==1)&&(full!=0))
            {
                consumer();
            }
            else{
                printf("buffer is empty!!");
            }
            break;
            case 3:
            exit(0);
            break;
            
        }	 	  	 	 	  	  	    	     	   	        	 	
    }
}
int wait(int s)
{
    return(--s);
}
int signal(int s)
{
    return(++s);
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProdcuer produces the intem %d",x);
    mutex=signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full=wait(full);
    empty = signal(empty);
    printf("\nConsumer consumers item %d",x);
    x--;
    mutex = signal(mutex);
}	 	  	 	 	  	  	    	     	   	        	 	
