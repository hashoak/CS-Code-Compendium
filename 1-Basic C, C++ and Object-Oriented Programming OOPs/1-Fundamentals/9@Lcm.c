#include<stdio.h>

int main()
{
    int a,b;

    printf("Type the two numbers in ascending order: ");
    scanf("%d%d", &a,&b);

    int i,j,l=1;
    for(i=a;i>1;i--)
    {
        for(j=2;j<i;j++)
        {
            if(!(i%j))
            {
                break;
            }
        }
        if(j==i)
        {
            if(!(a%i||b%i))
            {
                a/=i;
                b/=i;
                l*=i;
                i++;
            }
        }
    }
    printf("%d",a*b*l);
    return 0;
}