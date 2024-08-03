#include<stdio.h>
#include<stdlib.h>

void largestn(int*nums,int n);

int main()
{
    int n,i;
    scanf("%d",&n);
    int *nums;
    nums=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",nums+i);
    }
    largestn(nums,n);
    return 0;
}

void largestn(int *nums,int n)
{
    int i,m=0,p=0;
    for(i=0;i<n;i++)
    {
        if(*(nums+i)>m) m=*(nums+i),p=i;
    }
    printf("The largest element is %d and it's position is %d\n",m,p+1);
    return;
}