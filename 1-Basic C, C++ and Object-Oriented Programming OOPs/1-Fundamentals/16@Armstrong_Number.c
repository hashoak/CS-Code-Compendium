#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,j,d,a=n,m=0,r;
    for(i=0;a>0;i++)
    {
        a/=10;
    }
    d=i;
    a=n;
    for(i=0;a>0;i++)
    {
        r=a%10;
        int p=1;
        for(j=0;j<d;j++)
        {
            p*=r;
        }
        m+=p;
        a/=10;
    }

    if(n==m)
    {
        printf("Armstrong number");
    }
    else{
        printf("Not a Armstrong number");
    }

    return 0;
}