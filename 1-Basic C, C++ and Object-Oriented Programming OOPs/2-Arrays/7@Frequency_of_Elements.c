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
    printf("\nThe frequency of all elements of an array: \n");
    for(i=0;i<n;i++)
    {
        if(f[a[i]-1])
        {
            printf("%d occurs %d times\n",a[i],f[a[i]-1]);
        }
    }
    return 0;
}