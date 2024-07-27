#include<stdio.h>

int power(int a,int n)
{
    if(n==1) return a;
    return a*power(a,n-1);
}

int main()
{
    int a,n;
    scanf("%d%d",&a,&n);
    printf("%d\n",power(a,n));
    return 0;
}