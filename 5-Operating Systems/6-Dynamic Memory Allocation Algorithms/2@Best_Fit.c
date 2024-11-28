#include <stdio.h>
#include <stdlib.h>

struct Block
{
    int id;
    int size;
    int allocated;
};
typedef struct Block Block;

void bestFit(int numBlocks,Block* blocks,int numProcesses,int* processSize)
{
    printf("--------------------------------------\n");
    printf("Process No. | Process Size | Block no.\n");
    printf("--------------------------------------\n");
    for(int i=0;i<numBlocks;i++) blocks[i].allocated=0;
    for(int i=0;i<numProcesses;i++)
    {
        int bestFitIdx=-1;
        int minDiff=__INT_MAX__;
        for(int j=0;j<numBlocks;j++)
        {
            if(blocks[j].allocated==0 && blocks[j].size>=processSize[i])
            {
                int diff=blocks[j].size-processSize[i];
                if(diff<minDiff)
                {
                    bestFitIdx=j;
                    minDiff=diff;
                }
            }
        }
        printf("%-11d | %-12d | ",i+1,processSize[i]);
        if(bestFitIdx!=-1)
        {
            blocks[bestFitIdx].allocated=1;
            printf("%d\n",blocks[bestFitIdx].id);
        }
        else printf("Not Allocated\n");
    }
}

int main()
{
    int numBlocks;
    printf("Enter the number of memory blocks: ");
    scanf("%d",&numBlocks);
    Block* blocks=(Block*)calloc(numBlocks,sizeof(Block));
    printf("Enter the size of blocks: ");
    for(int i=0;i<numBlocks;i++)
    {
        blocks[i].id=i+1;
        scanf("%d",&blocks[i].size);
    }

    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d",&numProcesses);
    int processSize[numProcesses];
    printf("Enter the size of processes: ");
    for(int i=0;i<numProcesses;i++) scanf("%d",&processSize[i]);

    printf("\nBest fit memeory allocation:\n");
    bestFit(numBlocks,blocks,numProcesses,processSize);
    return 0;
}