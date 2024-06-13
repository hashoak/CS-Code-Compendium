#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,t,a=0,b=1;
    printf("1");
    for(i=1;i<n;i++)
    {
        printf(", %d",a+b);
        t=a;
        a=b;
        b+=t;
    }

    return 0;
}