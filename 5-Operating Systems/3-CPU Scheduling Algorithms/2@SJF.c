#include<stdio.h>
#include<stdlib.h>

struct Process
{
    int id,done;
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
    int pct=0,li=0;
    Process* lbt;
    for(int i=0;i<n;i++)
    {
        lbt=processes+li;
        for(int j=li+1;j<n && processes[j].at<=pct;j++)
        {
            if(!processes[j].done && processes[j].bt<lbt->bt) lbt=processes+j;
        }
        pct+=lbt->bt;
        lbt->ct=pct;
        lbt->tat=pct-lbt->at;
        lbt->wt=lbt->tat-lbt->bt;
        lbt->done=1;
        while(processes[li].done) li++;
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    Process processes[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %f %f",&processes[i].id,&processes[i].at,&processes[i].bt);
        processes[i].done=0;
    }
    calc_processes(n,processes);
    float avg_tat=0,avg_wt=0;
    for(int i=0;i<n;i++) avg_tat+=processes[i].tat,avg_wt+=processes[i].wt;
    avg_tat/=n,avg_wt/=n;
    printf("Average Turn Around Time: %f\n",avg_tat);
    printf("Average Wait Time: %f",avg_wt);
    return 0;
}
