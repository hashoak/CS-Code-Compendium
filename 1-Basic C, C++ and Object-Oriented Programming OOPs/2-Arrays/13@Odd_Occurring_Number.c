#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,m=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>m)
        {
            m=a[i];
        }
    }
    int b[m];
    for(i=0;i<m;i++)
    {
        b[i]=0;
    }
    printf("The given array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        b[a[i]-1]++;
    }
    int on;
    for(i=0;i<m;i++)
    {
        if(b[i]%2)
        {
            on=i+1;
        }
    }
    printf("\nThe element odd number of times is: %d",on);
    return 0;
}