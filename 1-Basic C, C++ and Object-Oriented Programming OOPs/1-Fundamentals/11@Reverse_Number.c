#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,m=0;
    for(i=0;n>0;i++)
    {
        m=m*10+n%10;
        n/=10;
    }

    printf("Reverse number: %d",m);

    return 0;
}