#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,j;
    printf("1");
    for(i=2;i<=n;i++)
    {
        if(!(n%i))
        {
            printf(",%d",i);
        }
    }

    return 0;
}