#include<stdio.h>

int main()
{
    int n,p;

    printf("Type the number: ");
    scanf("%d", &n);
    printf("Type the power: ");
    scanf("%d", &p);

    int i,a=1;
    for(i=0;i<p;i++)
    {
        a*=n;
    }

    printf("%d^%d=%d",n,p,a);

    return 0;
}