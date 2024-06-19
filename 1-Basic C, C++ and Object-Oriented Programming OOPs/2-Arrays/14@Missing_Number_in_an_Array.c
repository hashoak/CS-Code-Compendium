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
        b[i]=1;
    }
    printf("The given array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        b[a[i]-1]=0;
    }
    int mn;
    for(i=0;i<m;i++)
    {
        if(b[i])
        {
            mn=i+1;
        }
    }
    printf("\nThe missing number is: %d",mn);
    return 0;
}