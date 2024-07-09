#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=0;
    for(i=0;i<n;i++)
    {
        s+=a[i];
    }
    printf("Sum of all elements stored in the array is: %d",s);
    return 0;
}