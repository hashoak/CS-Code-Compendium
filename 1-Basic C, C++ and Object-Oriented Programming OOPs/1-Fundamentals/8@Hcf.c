#include<stdio.h>

int main()
{
    int a,b;

    printf("Type two numbers: ");
    scanf("%d%d", &a,&b);

    int i,h=1;
    for(i=2;i<=a;i++)
    {
        if(!(a%i) && !(b%i))
        {
            h=i;
        }
    }

    printf("HCF: %d",h);

    return 0;
}