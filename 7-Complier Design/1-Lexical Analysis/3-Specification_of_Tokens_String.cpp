#include <iostream>
#include <string>
using namespace std;

void printPrefix(const string str)
{
    cout<<"Prefixes: ";
    cout<<char(238);
    for(int i=0;i<str.length();i++)
    {
        cout<<", "<<str.substr(0,i+1);
    }
    cout<<"\n\n";
}

void printSuffix(const string str)
{
    cout<<"Suffixes: ";
    for(int i=0;i<str.length();i++)
    {
        cout<<str.substr(i,str.length()-i)<<", ";
    }
    cout<<char(238)<<"\n\n";
}

void printSubstring(const string str)
{
    cout<<"Substrings: ";
    cout<<char(238);
    for(int i=0;i<str.length();i++)
    {
        for(int j=i;j<str.length();j++)
        {
            cout<<", "<<str.substr(i,j-i+1);
        }
    }
    cout<<"\n\n";
}

void printProperPrefix(const string str)
{
    cout<<"Proper Prefixes: ";
    for(int i=0;i<str.length()-1;i++)
    {
        if(i) cout<<", ";
        cout<<str.substr(0,i+1);
    }
    cout<<"\n\n";
}

void printProperSuffix(const string str)
{
    cout<<"Proper Suffixes: ";
    for(int i=0;i<str.length()-1;i++)
    {
        if(i) cout<<", ";
        cout<<str.substr(i+1,str.length()-i+1);
    }
    cout<<"\n\n";
}

void printSubsequence(const string str)
{
    cout<<"Subsequences: ";
    cout<<char(238);
    int n=str.length();
    for(int i=1;i<(1<<n);i++)
    {
        string subseq;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                subseq += str[j];
            }
        }
        cout<<", "<<subseq;
    }
    cout<<"\n\n";
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"\n";

    printPrefix(str);
    printSuffix(str);
    printSubstring(str);
    printProperPrefix(str);
    printProperSuffix(str);
    printSubsequence(str);

    return 0;
}
