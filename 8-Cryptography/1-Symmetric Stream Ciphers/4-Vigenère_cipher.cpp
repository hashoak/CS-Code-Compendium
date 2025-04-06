#include<bits/stdc++.h>
using namespace std;    

int main()
{
    string plain,key;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<"Enter the plain text: ";
    cin>>plain;

    int pl=plain.length(),kl=key.length();
    string cipher="";
    for(int i=0;i<pl;i++)
        cipher+=((plain[i]-'a'+key[i%kl]-'a')%26)+'a';
    cout<<"Encrypted text: "<<cipher<<endl;

    plain="";
    for(int i=0;i<pl;i++)
        plain+=((cipher[i]-'a'-key[i%kl]+'a'+26)%26)+'a';
    cout<<"Decrypted text: "<<plain<<endl;

    return 0;
}