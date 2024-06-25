#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i;
    for(i=2;i<n;i++)
    {
        if(!(n%i))
        {
            printf("Composite");
            return 0;
        }
    }

    printf("Prime");

    return 0;
}