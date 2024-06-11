#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f*=i;
    }
    
    printf("Factorial: %d",f);

    return 0;
}