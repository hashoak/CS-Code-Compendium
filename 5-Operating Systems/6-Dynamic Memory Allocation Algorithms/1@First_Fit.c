#include <stdio.h>
#include <stdlib.h>

struct Block
{
    int id;
    int size;
    int allocated;
};
typedef struct Block Block;

void firstFit(int numBlocks,Block* blocks,int numProcesses,int* processSize)
{
    printf("--------------------------------------\n");
    printf("Process No. | Process Size | Block no.\n");
    printf("--------------------------------------\n");
    for(int i=0;i<numBlocks;i++) blocks[i].allocated=0;
    for(int i=0;i<numProcesses;i++)
    {
        int j;
        printf("%-11d | %-12d | ",i+1,processSize[i]);
        for(j=0;j<numBlocks;j++)
        {
            if(blocks[j].allocated==0 && blocks[j].size>=processSize[i])
            {
                blocks[j].allocated=1;
                printf("%d\n",blocks[j].id);
                break;
            }
        }
        if(j==numBlocks) printf("Not Allocated\n");
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

    printf("First fit memeory allocation:\n");
    firstFit(numBlocks,blocks,numProcesses,processSize);
    return 0;
}