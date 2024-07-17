#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n],i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        int m=0,mi;
        for(j=0;j<n;j++)
        {
            if(a[j]>m)
            {
                m=a[j];
                mi=j;
            }
        }
        a[mi]=0;
        b[n-i-1]=m;
    }
    printf("\nElements of array in sorted ascending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}