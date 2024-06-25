#include<stdio.h>

int main()
{
    int a,b;

    printf("Type the two numbers: ");
    scanf("%d%d", &a,&b);

    int i,j,x=0;
    for(i=a+1;i<b;i++)
    {
        for(j=2;j<i;j++)
        {
            if(!(i%j))
            {
                break;
            }
        }
        if(j==i)
        {
            if(x){printf(",");}
            x++;
            printf("%d",i);
        }
    }

    return 0;
}