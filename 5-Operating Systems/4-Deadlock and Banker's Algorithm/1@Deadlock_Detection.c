#include<stdio.h>
#include<stdlib.h>

int* isDead(int p,int r,int **alloc,int **req,int *avail)
{
    int i,j;
    int work[r],finish[p],ind=0;
    int *ans=(int*)calloc(p,sizeof(int));
    for(i=0;i<r;i++) work[i]=avail[i];
    for(i=0;i<p;i++) finish[i]=0;
    for(int k=0;k<p;k++)
    {
        for(i=0;i<p;i++)
        {
            if(!finish[i])
            {
                for(j=0;j<r;j++)
                {
                    if(req[i][j]>work[j]) break;
                }
                if(j==r)
                {
                    ans[ind++]=i;
                    for(j=0;j<r;j++) work[j]+=alloc[i][j];
                    finish[i]=1;
                    break;
                }
            }
        }
    }
    for(i=0;i<p;i++) if(!finish[i]) return NULL;
    return ans;
}

int main()
{
    int p,r;
    printf("Enter the no.of processes:");
    scanf("%d",&p);
    printf("Enter the no.of resource types:");
    scanf("%d",&r);
    int **alloc=(int**)calloc(p,sizeof(int*));
    int **req=(int**)calloc(p,sizeof(int*));
    int *avail=(int*)calloc(r,sizeof(int));
    for(int i=0;i<p;i++)
    {
        alloc[i]=(int*)calloc(r,sizeof(int));
        req[i]=(int*)calloc(r,sizeof(int));
    }
    
    printf("Enter the Allocation matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++) scanf("%d",&alloc[i][j]);
    }
    printf("Enter the Request matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++) scanf("%d",&req[i][j]);
    }
    printf("Enter the Available matrix:\n");
    for(int j=0;j<r;j++) scanf("%d",&avail[j]);
    
    int *ans=isDead(p,r,alloc,req,avail);
    if(ans!=NULL)
    {
        printf("There is no Deadlock\nSequence of allocation: ");
        for(int i=0;i<p-1;i++) printf("P%d->",ans[i]);
        printf("P%d",ans[p-1]);
    }
    else printf("The system is in Deadlock\n");
    return 0;
}