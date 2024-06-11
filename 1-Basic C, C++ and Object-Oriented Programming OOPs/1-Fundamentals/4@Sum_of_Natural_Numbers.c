#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,s=0;
    for(i=1;i<=n;i++)
    {
        s+=i;
    }
    
    printf("Sum: %d",s);

    return 0;
}