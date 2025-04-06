#include <bits/stdc++.h>
using namespace std;

void search(char kt[5][5],char a,char b,int* arr)
{
    int i,j;
    if(a=='j') a='i';
    else if(b=='j') b='i';
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(kt[i][j]==a) arr[0]=i,arr[1]=j;
            else if(kt[i][j]==b) arr[2]=i,arr[3]=j;
        }
    }
}

void encrypt(string& s,char kt[5][5],int sl)
{
    int i,a[4];
    for(i=0;i<sl;i+=2)
    {
        search(kt,s[i],s[i+1],a);
        if(a[0]==a[2])
        {
            s[i]=kt[a[0]][(a[1]+1)%5];
            s[i+1]=kt[a[0]][(a[3]+1)%5];
        }
        else if(a[1]==a[3])
        {
            s[i]=kt[(a[0]+1)%5][a[1]];
            s[i+1]=kt[(a[2]+1)%5][a[1]];
        }
        else
        {
            s[i]=kt[a[0]][a[3]];
            s[i+1]=kt[a[2]][a[1]];
        }
    }
}

void decrypt(string& s,char kt[5][5],int sl)
{
    int i,a[4];
    for(i=0;i<sl;i+=2)
    {
        search(kt,s[i],s[i+1],a);
        if(a[0]==a[2])
        {
            s[i]=kt[a[0]][(a[1]-1+5)%5];
            s[i+1]=kt[a[0]][(a[3]-1+5)%5];
        }
        else if(a[1]==a[3])
        {
            s[i]=kt[(a[0]-1+5)%5][a[1]];
            s[i+1]=kt[(a[2]-1+5)%5][a[1]];
        }
        else
        {
            s[i]=kt[a[0]][a[3]];
            s[i+1]=kt[a[2]][a[1]];
        }
    }
}

void makeKeyTable(string k,int kl,char kt[5][5])
{
    int i,j,x,flag=0;
    int dicty[26]={0};
    for(i=0;i<kl;i++)
        if(k[i]!='j')
            dicty[k[i]-97]=2;

    dicty['j'-97]=1;
    i=0,j=0;

    for(x=0;x<kl;x++)
    {
        if(dicty[k[x]-97]==2)
        {
            dicty[k[x]-97]-=1;
            kt[i][j]=k[x];
            j++;
            if(j==5) i++,j=0;
        }
    }

    for(x=0;x<26;x++)
    {
        if(dicty[x]==0)
        {
            kt[i][j]=(char)(x+97);
            j++;
            if(j==5) i++,j=0;
        }
    }
}

int main()
{
    string str,key;
    cout<<"Key text: ";
    cin>>key;
    cout<<"Plain text: ";
    cin>>str;

    char sl,ks,keyT[5][5];
    ks=key.length();
    sl=str.length();
    if(sl%2!=0)
    {
        str[sl++]='z';
        str[sl]='\0';
    }
    makeKeyTable(key,ks,keyT);

    encrypt(str,keyT,sl);
    cout<<"Cipher text: "<<str<<"\n";

    decrypt(str,keyT,sl);
    cout<<"Plain text: "<<str<<"\n";

    return 0;
}