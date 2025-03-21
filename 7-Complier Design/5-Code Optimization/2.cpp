#include <bits/stdc++.h>
using namespace std;

void deadCodeElimination(vector<pair<string,string>> &variables)
{
    for (int i=0;i<variables.size()-1;i++)
    {
        bool used = 0;
        for (int j=i+1;j<variables.size();j++)
        {
            if(i==j) continue;
            size_t signPos = variables[j].second.find_first_of("+-*/");
            if (signPos == string::npos) used = (used || variables[i].first == variables[j].second);
            else
            {
                string op1 = variables[j].second.substr(0, signPos);
                string op2 = variables[j].second.substr(signPos + 1);
                used = (used || variables[i].first == op1 || variables[i].first == op2);
            }
        }
        if(!used) variables.erase(variables.begin()+i);
    }
    return;
}

void commonExpressionElimination(vector<pair<string,string>> &variables)
{
    for (int i=0;i<variables.size();i++)
    {
        for (int j=i+1;j<variables.size();j++)
        {
            if(variables[i].first!=variables[j].first && variables[i].second==variables[j].second)
            {
                for(int k=j+1;k<variables.size();k++)
                {
                    size_t signPos = variables[k].second.find_first_of("+-*/");
                    if (signPos == string::npos) continue;
                    string op1 = variables[k].second.substr(0, signPos);
                    char op=variables[k].second[signPos];
                    string op2 = variables[k].second.substr(signPos + 1);
                    if(op1==variables[j].first) op1=variables[i].first;
                    if(op2==variables[j].first) op2=variables[i].first;
                    variables[k].second=op1+op+op2;
                }
                variables[j].first=variables[i].first;
            }
        }
    }
    return;
}

void optimizedCode(vector<pair<string,string>> &variables)
{
    for (int i=0;i<variables.size();i++)
    {
        for (int j=i+1;j<variables.size();j++)
        {
            if(variables[i].first==variables[j].first && variables[i].second==variables[j].second)
                variables.erase(variables.begin()+j);
        }
    }
    return;
}

int main()
{
    ifstream input("input2.txt");
    vector<pair<string, string>> variables;
    string line;
    while (getline(input, line))
    {
        size_t equalPos = line.find('=');
        string variable = line.substr(0, equalPos);
        string operation = line.substr(equalPos + 1);
        variables.push_back(make_pair(variable, operation));
    }
    deadCodeElimination(variables);
    cout<<"After dead code elimination\n";
    for(auto i:variables) cout<<i.first<<"="<<i.second<<"\n";

    commonExpressionElimination(variables);
    cout<<"\nEliminate Common Expression\n";
    for(auto i:variables) cout<<i.first<<"="<<i.second<<"\n";

    optimizedCode(variables);
    cout<<"\nAfter dead code elimination\n";
    for(auto i:variables) cout<<i.first<<"="<<i.second<<"\n";
    return 0;
}
