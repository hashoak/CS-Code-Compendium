#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i;
    for(i=0;n>0;i++)
    {
        n/=10;
    }

    printf("No. of digits: %d",i);

    return 0;
}