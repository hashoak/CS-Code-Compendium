#include<stdio.h>
#include<math.h>

void primes_btw(int a,int b)
{
    int i,j;
    for(i=a;i<=b;i++)
    {
        if(i==2 || (i>1 && i%2))
        {
            for(j=3;j<=sqrt(i);j+=2)
            {
                if(i%j==0)
                {
                    break;
                }
            }
            if(j>sqrt(i))
            {
                printf("%d ",i);
            }
        }
    }
    return;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    primes_btw(a,b);
    return 0;
}