#include<stdio.h>

int main()
{
    int n;

    printf("Type the number: ");
    scanf("%d", &n);

    int i,a=n,m=0;
    for(i=0;a>0;i++)
    {
        m=m*10+a%10;
        a/=10;
    }

    if(n==m)
    {
        printf("Palindrome");
    }
    else{
        printf("Not a Palindrome");
    }

    return 0;
}