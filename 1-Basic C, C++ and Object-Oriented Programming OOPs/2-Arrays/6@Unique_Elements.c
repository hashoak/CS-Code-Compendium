#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],m=0,i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(m<a[i])
        {
            m=a[i];
        }
    }
    int f[m],nd=0;
    for(i=0;i<m;i++)
    {
        f[i]=0;
    }
    for(i=0;i<n;i++)
    {
        f[a[i]-1]++;
    }
    printf("\nThe unique elements found in the array are: \n");
    for(i=0;i<m;i++)
    {
        if(f[i]==1)
        {
            printf("%d ",i+1);
        }
    }
    return 0;
}