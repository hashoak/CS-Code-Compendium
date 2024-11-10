#include<iostream> 
#include<algorithm> 
using namespace std; 
 
struct Process 
{ 
    int id,pr,done; 
    float at,bt,rbt,ct,tat,wt; 
}; 
typedef struct Process Process; 
 
int cmpfunc(Process a,Process b) {return a.at<b.at; } 
 
void nonPreemptivePriority(int n,Process processes[]) 
{ 
    sort(processes,processes+n,cmpfunc); 
    int pct=0,li=0; 
    Process* hp; 
    for(int i=0;i<n;i++) 
    { 
        hp=processes+li; 
        for(int j=li+1;j<n && processes[j].at<=pct;j++) 
        { 
            if(!processes[j].done && processes[j].pr>hp->pr) hp=processes+j; 
        } 
        pct+=hp->bt; 
        hp->ct=pct; 
        hp->tat=pct-hp->at; 
        hp->wt=hp->tat-hp->bt; 
        hp->done=1; 
        while(processes[li].done) li++; 
    } 
    float atat=0,awt=0; 
    for(int i=0;i<n;i++) atat+=processes[i].tat,awt+=processes[i].wt,processes[i].done=0; 
    atat/=n,awt/=n; 
    cout<<"Preemptive Priority\n"; 
    cout<<"Average Turn Around Time: "<<atat<<"\n"; 
    cout<<"Average Waiting Time: "<<awt<<"\n"; 
    cout<<"\n"; 
    return; 
} 
 
void preemptivePriority(int n,Process processes[]) 
{ 
    sort(processes,processes+n,cmpfunc); 
    int pct=0,li=0; 
    Process* hp; 
    while(li<n) 
    { 
        hp=processes+li; 
        for(int j=li+1;j<n && processes[j].at<=pct;j++) 
        { 
            if(!processes[j].done && processes[j].pr>hp->pr) hp=processes+j; 
        } 
        hp->rbt--,pct++; 
        if(!hp->rbt) 
        { 
            hp->ct=pct; 
            hp->tat=pct-hp->at; 
            hp->wt=hp->tat-hp->bt; 
            hp->done=1; 
            while(processes[li].done) li++; 
        } 
    } 
    float atat=0,awt=0; 
    for(int i=0;i<n;i++) atat+=processes[i].tat,awt+=processes[i].wt,processes[i].done=0; 
    atat/=n,awt/=n; 
    cout<<"Preemptive Priority\n"; 
    cout<<"Average Turn Around Time: "<<atat<<"\n"; 
    cout<<"Average Waiting Time: "<<awt<<"\n"; 
    cout<<"\n"; 
    return; 
} 
 
int main() 
{ 
    int n; 
    cin>>n; 
    Process processes[n]; 
    for(int i=0;i<n;i++) 
    { 
        cin>>processes[i].id>>processes[i].at>>processes[i].bt>>processes[i].pr; 
        processes[i].done=0,processes[i].rbt=processes[i].bt; 
    } 
    nonPreemptivePriority(n,processes); 
    preemptivePriority(n,processes); 
    return 0; 
}