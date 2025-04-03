#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int key;
    cout<<"Enter the key: ";
    cin>>key;

    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]=((str[i]-'a'+key)%26)+'a';
        else if(str[i]>='A' && str[i]<='Z')
            str[i]=((str[i]-'A'+key)%26)+'A';
    }
    cout<<"Encrypted string: "<<str<<endl;

    for(int i=0;i<len;i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]=((str[i]-'a'-key+26)%26)+'a';
        else if(str[i]>='A' && str[i]<='Z')
            str[i]=((str[i]-'A'-key+26)%26)+'A';
    }
    cout<<"Decrypted string: "<<str<<endl;

    return 0;
}