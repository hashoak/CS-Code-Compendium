#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int freq;
    char val;
    Node *left,*right;
    Node(int f,char v)
    {
        freq=f;
        val=v;
        left=right=NULL;
    }
};

class compare
{
    public:
    bool operator()(Node* l,Node* r)
    {
        return (l->freq>=r->freq);
    }
};

void traceCode(Node* root,Node** data,string* hcodes,string str="")
{
    if(root->val!='~')
    {
        char val=root->val;
        int i=0;
        while(data[i]->val!=val) i++;
        hcodes[i]=str;
        return;
    }
    traceCode(root->left,data,hcodes,str+"0");
    traceCode(root->right,data,hcodes,str+"1");
}

void HuffmanCodes(Node** data,int n,string* hcodes)
{
    Node *left,*right,*top;
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    for(int i=0;i<n;i++) minHeap.push(data[i]);
    while(minHeap.size()!=1)
    {
        left=minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();
        top=new Node(left->freq+right->freq,'~');
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    traceCode(minHeap.top(),data,hcodes);
    return;
}

int main()
{
    int n,f;
    cin>>n;
    char chars[n]={'A','I','Y','V','R','E','T'};
    Node** data=new Node*[n];
    for(int i=0;i<n;i++) 
    {
        cin>>f;
        data[i]=new Node(f,chars[i]);
    }
    string codes[n];
    HuffmanCodes(data,n,codes);
    for(string i:codes) cout<<i<<" ";
    return 0;
}