#include<stdio.h>

int bin(int n)
{
    int b=0,m=1;
    while(n)
    {
        b=n%2*m+b;
        n/=2;
        m*=10;
    }
    return b;
}

int dec(int n)
{
    int d=0,m=1;
    while(n)
    {
        d+=n%10*m;
        n/=10;
        m*=2;
    }
    return d;
}

int main()
{
    int d,b;
    scanf("%d%d",&d,&b);
    printf("Binary form of %d is: %d\n",d,bin(d));
    printf("Decimal form of %d is: %d\n",b,dec(b));
    return 0;
}