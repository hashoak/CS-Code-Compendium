#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=0;
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    printf("The elements stored in the first array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nThe elements copied into the second array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}