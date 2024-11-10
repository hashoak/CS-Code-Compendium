#include<stdio.h>
#include<stdlib.h>

struct Process
{
    int id;
    float at,bt,ct,tat,wt;  
};
typedef struct Process Process;

int cmpfunc(const void* a,const void* b)
{
    return ((Process*)a)->at>((Process*)b)->at;
}

void calc_processes(int n,Process* processes)
{
    qsort(processes,n,sizeof(Process),cmpfunc);
    int pct=0;
    for(int i=0;i<n;i++)
    {
        pct+=processes[i].bt;
        processes[i].ct=pct;
        processes[i].tat=processes[i].ct-processes[i].at;
        processes[i].wt=processes[i].tat-processes[i].bt;
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    Process processes[n];
    for(int i=0;i<n;i++) scanf("%d %f %f",&processes[i].id,&processes[i].at,&processes[i].bt);
    calc_processes(n,processes);
    float avg_tat=0;
    for(int i=0;i<n;i++) avg_tat+=processes[i].tat;
    avg_tat/=n;
    printf("Average Turn Around Time: %f",avg_tat);
    return 0;
}
