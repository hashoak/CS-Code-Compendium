#include<stdio.h>

int sumofn(int n)
{
    if(!n) return 0;
    return n+sumofn(n-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",sumofn(n));
    return 0;
}