#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],o=0,e=0,i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2) o++;
        else e++;
    }
    int odd[o],even[e],oi=0,ei=0,s=0,p=1;
    for(i=0;i<n;i++)
    {
        if(a[i]%2) odd[oi]=a[i],oi++,s+=a[i];
        else even[ei]=a[i],ei++,p*=a[i];
    }
    printf("The odd numbers are: ");
    for(i=0;i<oi;i++)
    {
        printf("%d ",odd[i]);
    }
    printf("\nAnd their sum is: %d",s);
    printf("\nThe even numbers are: ");
    for(i=0;i<ei;i++)
    {
        printf("%d ",even[i]);
    }
    printf("\nAnd their product is: %d",p);
    return 0;
}