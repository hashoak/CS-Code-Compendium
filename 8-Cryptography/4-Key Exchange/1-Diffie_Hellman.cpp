#include <iostream>
#include <cmath>
using namespace std;

long long int power(long long int a,long long int b,long long int P)
{
	if(b==1) return a;
	else return (((long long int)pow(a,b))%P);
}

int main()
{
	long long int P,G,x,a,y,b,ka,kb;
	cout<<"Enter the value of P: ";
    cin>>P;
	cout<<"Enter the value of G: ";
    cin>>G;
	cout<<"Enter the private key of party1: ";
    cin>>a;
	cout<<"Enter the private key of party2: ";
    cin>>b;

	x=power(G,a,P);
	y=power(G,b,P);
	ka=power(y,a,P);
	kb=power(x,b,P);

	cout<<"Public key for the Alice is: "<<x<<"\n";
	cout<<"Public key for the Bob is: "<<y<<"\n";
	cout<<"Secret key for the Alice is: "<<ka<<"\n";
	cout<<"Secret key for the Bob is: "<<kb<<"\n";
	return 0;
}