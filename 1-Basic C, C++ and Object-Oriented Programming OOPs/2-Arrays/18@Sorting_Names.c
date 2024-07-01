#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    char names[n][1000],t[1000];
    for(i=0;i<n;i++)
    {
        scanf("%s",names[i]);
    }
    for(i=1;i<n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(strcmp(names[j],names[j+1])>0)
            {
                strncpy(t,names[j],1000);
                strncpy(names[j],names[j+1],1000);
                strncpy(names[j+1],t,1000);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s\n",names[i]);
    }
    return 0;
}