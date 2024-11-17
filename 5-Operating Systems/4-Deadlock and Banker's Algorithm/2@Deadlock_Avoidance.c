#include<stdio.h>
#include<stdlib.h>

int* isSafe(int p,int r,int **alloc,int **max,int *avail)
{
    int i,j;
    int need[p][r],work[r],finish[p],ind=0;
	int *ans=(int*)calloc(p,sizeof(int));
    for(i=0;i<p;i++)
    {
		for(j=0;j<r;j++) need[i][j]=max[i][j]-alloc[i][j];
	}
	for(i=0;i<p;i++) finish[i]=0;
	for(i=0;i<r;i++) work[i]=avail[i];
	for(int k=0;k<p;k++)
    {
		for(i=0;i<p;i++)
        {
			if(!finish[i])
            {
				for(j=0;j<r;j++)
                {
					if(need[i][j]>work[j]) break;
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
	int **max=(int**)calloc(p,sizeof(int*));
	int *avail=(int*)calloc(r,sizeof(int));
    for(int i=0;i<p;i++)
    {
        alloc[i]=(int*)calloc(r,sizeof(int));
        max[i]=(int*)calloc(r,sizeof(int));
    }

    printf("Enter the Allocation matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++) scanf("%d",&alloc[i][j]);
    }
    printf("Enter the Max matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++) scanf("%d",&max[i][j]);
    }
    printf("Enter the Available matrix:\n");
    for(int j=0;j<r;j++) scanf("%d",&avail[j]);

    int* ans=isSafe(p,r,alloc,max,avail);
	if(ans!=NULL)
	{
        printf("The system is safe\nSequence: ");
        for(int i=0;i<p-1;i++) printf("P%d->",ans[i]);
        printf("P%d",ans[p-1]);
	}
    else printf("The system is not safe\n");
	return 0;
}