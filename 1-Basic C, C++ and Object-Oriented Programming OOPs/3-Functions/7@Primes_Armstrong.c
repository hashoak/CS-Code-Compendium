#include<stdio.h>
#include<math.h>

int isprime(int n)
{
    int i;
    if(n<3)
    {
        return n==2;
    }
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            break;
        }
    }
    return 1;
}

int isamstng(int n)
{
    int a=0,m=n,i;
    while(n)
    {
        i=n%10;
        n/=10;
        a+=i*i*i;
    }
    return m==a;
}

int main()
{
    int n;
    scanf("%d",&n);
    if(isprime(n) && isamstng(n))
    {
        printf("The number is Prime as well as Armstrong.\n");
    }
    else if(isprime(n) && !isamstng(n))
    {
        printf("The number is Prime, but not Armstrong.\n");
    }
    else if(!isprime(n) && isamstng(n))
    {
        printf("The number is Armstrong, but not Prime.\n");
    }
    else
    {
        printf("The number is nor Prime neither Armstrong.\n");
    }
    return 0;
}