#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Process
{
    int id;
    float at,bt,rbt,ct,tat,wt;
};
typedef struct Process Process;

int cmpfunc(Process a,Process b) {return a.at<b.at; }

void print(queue<Process*> q)
{
    if(q.empty()) return;
    Process* x=q.front();
    q.pop();
    print(q);
    cout<<"P"<<x->id<<"->";
    q.push(x);
}

void roundRobin(int n,Process processes[])
{
    sort(processes,processes+n,cmpfunc);
    float quantum=2;
    queue<Process*> ready;
    ready.push(processes);
    int pct=0,li=1;
    Process* rp;
    while(!ready.empty())
    {
        rp=ready.front();
        ready.pop();
        while(li<n && processes[li].at<=pct+min(rp->rbt,quantum)) ready.push(processes+li++);
        if(rp->rbt<=quantum)
        {
            pct+=rp->rbt;
            rp->rbt=0;
            rp->ct=pct;
            rp->tat=pct-rp->at;
            rp->wt=rp->tat-rp->bt;
        }
        else
        {
            pct+=quantum;
            rp->rbt-=quantum;
            ready.push(rp);
        }
    }
    float atat=0,awt=0;
    for(int i=0;i<n;i++) atat+=processes[i].tat,awt+=processes[i].wt;
    atat/=n,awt/=n;
    cout<<"\nAverage Turn Around Time: "<<atat<<"\n";
    cout<<"Average Waiting Time: "<<awt<<"\n";
    return;
}

int main()
{
    int n;
    cin>>n;
    Process processes[n];
    // for(int i=0;i<n;i++)
    for(auto &i:processes)
    {
        cin>>i.id>>i.at>>i.bt;
        i.rbt=i.bt;
    }
    roundRobin(n,processes);
    return 0;
}