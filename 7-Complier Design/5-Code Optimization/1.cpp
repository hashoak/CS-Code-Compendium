#include<bits/stdc++.h>
using namespace std;

string evaluate(string op1,char op,string op2)
{
    int res;
    if(op=='+') res=stoi(op1)+stoi(op2);
    else if(op=='-') res=stoi(op1)-stoi(op2);
    else if(op=='*') res=stoi(op1)*stoi(op2);
    else if(op=='/') res=stoi(op1)/stoi(op2);
    return to_string(res);
}

void constantPropogation(map<string, string> variables)
{
    for(auto i:variables)
    {
        size_t signPos = i.second.find_first_of("+-*/");
        if(signPos==string::npos) continue;
        string op1 = i.second.substr(0,signPos);
        char op=i.second[signPos];
        string op2=i.second.substr(signPos+1);
        if(variables[op1]!="") op1=variables[op1];
        if(variables[op2]!="") op2=variables[op2];
        i.second=op1+op+op2;
        string result = evaluate(op1,op,op2);
        variables[i.first] = result;
        cout<<i.first<<"="<<i.second<<"\nResult: "<<result<<endl;
    }
    return;
}

int main()
{
    ifstream input("input1.txt");
    map<string, string> variables;
    string line;
    while (getline(input, line))
    {
        size_t equalPos = line.find('=');
        string variable = line.substr(0, equalPos);
        string operation = line.substr(equalPos + 1);
        variables[variable]=operation;
    }
    constantPropogation(variables);
    return 0;
}
