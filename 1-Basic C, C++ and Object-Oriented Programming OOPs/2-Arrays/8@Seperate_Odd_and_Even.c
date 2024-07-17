#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],on=0,en=0,i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2)
        {
            on++;
        }
        else{
            en++;
        }
    }
    int o[on],e[en],oc=0,ec=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2)
        {
            o[oc]=a[i];
            oc++;
        }
        else{
            e[ec]=a[i];
            ec++;
        }
    }
    printf("\nThe Even elements are: \n");
    for(i=0;i<ec;i++)
    {
        printf("%d ",e[i]);
    }
    printf("\nThe Odd elements are: \n");
    for(i=0;i<oc;i++)
    {
        printf("%d ",o[i]);
    }
    return 0;
}