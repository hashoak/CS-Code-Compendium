#include<stdio.h>

int oct(int n)
{
    int o=0,m=1;
    while(n)
    {
        o=n%8*m+o;
        n/=8;
        m*=10;
    }
    return o;
}

int dec(int n)
{
    int d=0,m=1;
    while(n)
    {
        d+=n%10*m;
        n/=10;
        m*=8;
    }
    return d;
}

int main()
{
    int d,o;
    scanf("%d%d",&d,&o);
    printf("Octal form of %d is: %d\n",d,oct(d));
    printf("Decimal form of %d is: %d\n",o,dec(o));
    return 0;
}