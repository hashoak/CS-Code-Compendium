#include <bits/stdc++.h>
using namespace std;

vector<string>splitString(string &str,char delimiter)
{
    vector<string>tokens;
    stringstream ss(str);
    string token;
    while(getline(ss,token,delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void constructDFA(int numStates,vector<string>stateLabels,string initialState,string finalState,map<string,map<string,string>>transitions)
{
    map<set<string>,map<string,set<string>>>dfaTransitions;

    set<string> eclosure;
    eclosure.insert(initialState);
    eclosure.insert(transitions[initialState]["^"]);

    set<string> states0,states1;
    for(string i:eclosure)
    {
        if(transitions[i]["^"]!="-") states0.insert(transitions[i]["^"]),states1.insert(transitions[i]["^"]);
        if(transitions[i]["0"]!="-") states0.insert(transitions[i]["0"]);
        if(transitions[i]["1"]!="-") states1.insert(transitions[i]["1"]);
    }
    dfaTransitions[eclosure]["0"]=states0;
    dfaTransitions[eclosure]["1"]=states1;

    eclosure=states1;
    states0.clear(),states1.clear();
    for(string i:eclosure)
    {
        if(transitions[i]["0"]!="-") states0.insert(transitions[i]["0"]);
        if(transitions[i]["1"]!="-") states1.insert(transitions[i]["1"]);
    }
    dfaTransitions[eclosure]["0"]=states0;
    dfaTransitions[eclosure]["1"]=states1;

    cout<<"Transition table of DFA:"<<endl;
    cout<<"----------------------------"<<endl;

    cout<<"State    |    0    |    1    "<<endl;
    cout<<"----------------------------"<<endl;

    string out;
    for(auto &transition:dfaTransitions)
    {
        out="[";
        for(auto i:transition.first) out+=i+' ';
        out[out.length()-1]=']';
        cout<<left<<setw(9)<<setfill(' ')<<out;
        cout<<"|";

        if(!transition.second.at("0").empty())
        {
            out="[";
            for(auto i:transition.second.at("0")) out+=i+' ';
            out[out.length()-1]=']';
            cout<<left<<setw(9)<<setfill(' ')<<out;
        }
        else cout<<left<<setw(9)<<setfill(' ')<<"-";
        cout<<"|";
        if(!transition.second.at("1").empty())
        {
            out="[";
            for(auto i:transition.second.at("1")) out+=i+' ';
            out[out.length()-1]=']';
            cout<<left<<setw(8)<<setfill(' ')<<out;
        }
        else cout<<left<<setw(9)<<setfill(' ')<<"-";
        cout<<"\n";
    }
    return;
}

int main()
{
    ifstream input("input4.txt");
    
    int numStates;
    input>>numStates;

    input.ignore();

    string stateLabelsStr;
    getline(input,stateLabelsStr);
    vector<string>stateLabels=splitString(stateLabelsStr,' ');

    string initialState;
    input>>initialState;

    string finalState;
    input>>finalState;

    input.ignore();

    map<string,map<string,string>>transitions;
    vector<string>transitionSymbols;
    string transitionStr;
    for(int i=0;i<numStates*3;i++)
    {
        getline(input,transitionStr);
        // cout<<transitionStr<<"\n";
        transitionSymbols=splitString(transitionStr,' ');
        transitions[transitionSymbols[0]][transitionSymbols[1]]=transitionSymbols[2];
    }

    constructDFA(numStates,stateLabels,initialState,finalState,transitions);

    return 0;
}