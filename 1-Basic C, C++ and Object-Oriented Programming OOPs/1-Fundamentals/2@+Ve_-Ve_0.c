#include<stdio.h>

int main()
{
    float i;

    printf("Type the number: ");
    scanf("%f", &i);
    if(i<0)
    {
        printf("Negative");
    }
    else if(i>0)
    {
        printf("Positive");
    }
    if(i==0)
    {
        printf("Zero");
    }

    return 0;
}