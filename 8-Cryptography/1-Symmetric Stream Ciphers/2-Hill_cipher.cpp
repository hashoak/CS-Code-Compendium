#include <bits/stdc++.h>
using namespace std;

string encrypt(string plain,int** key,int n)
{
    int len=plain.length();
    int* plain_mat=new int[len];
    for(int i=0;i<len;i++)
        plain_mat[i]=plain[i]-'a';
    string cipher="";
    int x;
    for(int i=0;i<len;i++)
    {
        x=0;
        for(int k=0;k<n;k++)
            x+=key[i%n][k]*plain_mat[i-i%n+k];
        cipher+=(x%26)+'a';
    }
    return cipher;
}

int determinant(int** key,int n)
{
    if(n==1) return key[0][0];    
    int det=0;
    int** submatrix=new int*[n-1];
    for(int i=0;i<n-1;i++)
        submatrix[i]=new int[n-1];
    
    for(int k=0;k<n;k++)
    {
        int sub_i=0;
        for(int i=1;i<n;i++)
        {
            int sub_j=0;
            for(int j=0;j<n;j++)
            {
                if(j!=k)
                {
                    submatrix[sub_i][sub_j]=key[i][j];
                    sub_j++;
                }
            }
            sub_i++;
        }
        int sign=(k%2==0) ? 1:-1;
        det+=sign*key[0][k]*determinant(submatrix,n-1);
    }
    return det;
}

int** adjoint(int** key,int n)
{
    int** adj=new int*[n];
    for(int i=0;i<n;i++)
        adj[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sign=((i+j)%2==0) ? 1 : -1;
            int** submatrix=new int*[n-1];
            for(int k=0;k<n-1;k++)
                submatrix[k]=new int[n-1];

            int sub_i=0;
            for(int row=0;row<n;row++)
            {
                if(row!=i)
                {
                    int sub_j=0;
                    for(int col=0;col<n;col++)
                    {
                        if(col!=j)
                        {
                            submatrix[sub_i][sub_j]=key[row][col];
                            sub_j++;
                        }
                    }
                    sub_i++;
                }
            }
            adj[j][i]=sign*determinant(submatrix,n-1);
        }
    }
    return adj;
}

int** inverse(int** key,int n)
{
    int det=(determinant(key,n)%26+26)%26;
    int deti=0;
    for(int i=0;!deti && i<26;i++)
        if((det*i)%26==1)
            deti=i;

    int** keyi=adjoint(key,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            keyi[i][j]=((keyi[i][j]%26+26)%26*deti)%26;
    
    return keyi;
}

int main()
{
    int n;
    cout<<"Enter the size of the key matrix: ";
    cin>>n;
    int** key=new int*[n];
    for(int i=0;i<n;i++)
        key[i]=new int[n];
    cout<<"Enter the key matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>key[i][j];
    string plain;
    cout<<"Enter the plain text: ";
    cin>>plain;

    string cipher=encrypt(plain,key,n);
    cout<<"Encrypted text: "<<cipher<<"\n";

    plain=encrypt(cipher,inverse(key,n),n);
    cout<<"Decrypted text: "<<plain<<"\n";
    
    return 0;
}