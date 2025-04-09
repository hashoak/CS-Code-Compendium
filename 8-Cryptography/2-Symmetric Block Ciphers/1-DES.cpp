#include<bits/stdc++.h>
using namespace std;

string rk[16];
string pt;

string decToBin(int d)
{
	string b;
    while(d !=0)
    {
		b=(d%2==0 ? "0":"1")+b;
		d=d/2;
	}
	while(b.length()<4)
        b="0"+b;
    return b;
}

int binToDec(string b)
{
    int d=0,c=0,s=b.length();
	for(int i=s-1;i >=0;i--)
    {
    	if(b[i]=='1')
        	d+=pow(2,c);
        c++;
	}
	return d;
}

string txtToBin(string s)
{
    string b="";
    for(int i=0;i<s.size();i++)
    {
        int x=int(s[i]);
        string bt="";
        while(x>0)
        {
            (x%2)?bt="1"+bt:bt="0"+bt;
            x/=2;
        }
        while(bt.size()<8)
            bt="0"+bt;
        b+=bt;
    }
    return b;
}

string binToTxt(string s)
{
    string t="";
    for(int i=0;i<s.size();i+=8)
    {
        string b=s.substr(i,8);
        int x=0;
        for(int j=0;j<8;j++)
            x=x*2+(b[j]-'0');
        t+=char(x);
    }
    return t;
}

string shift_left_once(string kc)
{
    string s="";
    for(int i=1;i<28;i++)
        s+=kc[i];
    s+=kc[0];
    return s;
}

string shift_left_twice(string kc)
{
    string s="";
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<28;j++)
            s+=kc[j];
        s+=kc[0];
        kc=s;
        s="";
    }
    return kc;
}

string Xor(string a,string b)
{
	string r="";
	int s=b.size();
	for(int i=0;i<s;i++)
		(a[i]!=b[i]) ? r+="1":r+="0";
	return r;
}

void generate_keys(string k)
{
	int pc1[56]=
    {
	    57,49,41,33,25,17,9,
	    1,58,50,42,34,26,18,
	    10,2,59,51,43,35,27,
	    19,11,3,60,52,44,36,		
	    63,55,47,39,31,23,15,
	    7,62,54,46,38,30,22,
	    14,6,61,53,45,37,29,
	    21,13,5,28,20,12,4
	};
	int pc2[48]=
    {
	    14,17,11,24,1,5,
	    3,28,15,6,21,10,
	    23,19,12,4,26,8,
	    16,7,27,20,13,2,
	    41,52,31,37,47,55,
	    30,40,51,45,33,48,
	    44,49,39,56,34,53,
	    46,42,50,36,29,32
	};
	string pk="";
	for(int i=0;i<56;i++)
		pk+=k[pc1[i]-1];
	string l=pk.substr(0,28);
	string r=pk.substr(28,28);
	for(int i=0;i<16;i++)
    {
		if(i==0 || i==1 || i==8 || i==15 )
        {
			l=shift_left_once(l);
			r=shift_left_once(r);
		}
		else
        {
			l=shift_left_twice(l);
			r=shift_left_twice(r);
		}
		string ck=l+r;
		string trk="";
		for(int i=0;i<48;i++)
			trk+=ck[pc2[i]-1];
		rk[i]=trk;
	}
}

string DES()
{
	int initial_permutation[64]=
    {
	    58,50,42,34,26,18,10,2,
	    60,52,44,36,28,20,12,4,
	    62,54,46,38,30,22,14,6,
	    64,56,48,40,32,24,16,8,
	    57,49,41,33,25,17,9,1,
	    59,51,43,35,27,19,11,3,
	    61,53,45,37,29,21,13,5,
	    63,55,47,39,31,23,15,7
	};
	int expansion_table[48]=
    {
	    32,1,2,3,4,5,4,5,
	    6,7,8,9,8,9,10,11,
	    12,13,12,13,14,15,16,17,
	    16,17,18,19,20,21,20,21,
	    22,23,24,25,24,25,26,27,
	    28,29,28,29,30,31,32,1
	};
	int substition_boxes[8][4][16]=
	{{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }};
	int permutation_tab[32]=
    {
	    16,7,20,21,29,12,28,17,
	    1,15,23,26,5,18,31,10,
	    2,8,24,14,32,27,3,9,
	    19,13,30,6,22,11,4,25
	};
	int inverse_permutation[64]=
    {
	    40,8,48,16,56,24,64,32,
	    39,7,47,15,55,23,63,31,
	    38,6,46,14,54,22,62,30,
	    37,5,45,13,53,21,61,29,
	    36,4,44,12,52,20,60,28,
	    35,3,43,11,51,19,59,27,
	    34,2,42,10,50,18,58,26,
	    33,1,41,9,49,17,57,25
	};
  	string p="";
	for(int i=0;i<64;i++)
		p+=pt[initial_permutation[i]-1];
	string l=p.substr(0,32);
	string r=p.substr(32,32);
	for(int i=0;i<16;i++)
    {
    	string re="";
    	for(int i=0;i<48;i++)
      		re+=r[expansion_table[i]-1];
		string x=Xor(rk[i],re);
		string ans="";
		for(int i=0;i<8;i++)
        {
      		string row1=x.substr(i*6,1)+x.substr(i*6+5,1);
      		int row=binToDec(row1);
      		string col1=x.substr(i*6+1,1)+x.substr(i*6+2,1)+x.substr(i*6+3,1)+x.substr(i*6+4,1);
			int col=binToDec(col1);
			int val=substition_boxes[i][row][col];
			ans+=decToBin(val);
		}
		string p2="";
		for(int i=0;i<32;i++)
			p2+=ans[permutation_tab[i]-1];
		x=Xor(p2,l);
		l=x;
		if(i<15)
        {
			string t=r;
			r=x;
			l=t;
		}
	}
	string c=l+r;
	string ct="";
	for(int i=0;i<64;i++)
		ct+=c[inverse_permutation[i]-1];
	return ct;
}

int main()
{
    string k;
    cout<<"Enter key: ";
    cin>>k;
    cout<<"Enter plain text: ";
    cin>>pt;
	k=txtToBin(k);
	pt=txtToBin(pt);
	string apt=pt;
  	generate_keys(k);
    cout<<"Plain text(bin): "<<pt<<endl;
    string ct=DES();
    cout<<"Ciphertext(bin): "<<ct<<endl;
	int i=15;
	int j=0;
	while(i>j)
	{
		string t=rk[i];
		rk[i]=rk[j];
		rk[j]=t;
		i--,j++;
	}
	pt=ct;
	string dt=DES();
	cout<<"Decrypted text: "<<binToTxt(dt)<<endl;
	cout<<"Decrypted text(bin): "<<dt<<endl;
} 