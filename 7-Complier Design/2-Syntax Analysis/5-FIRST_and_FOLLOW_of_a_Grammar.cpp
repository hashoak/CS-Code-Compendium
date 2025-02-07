#include<bits/stdc++.h>
using namespace std;

vector<string>splitString(string& str,char delimiter)
{
    vector<string>tokens;
    string token;
    istringstream tokenStream(str);
    while(getline(tokenStream,token,delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

set<string> ss;
bool dfs(string i,string org,string last,map<string,vector<vector<string>>> &mp)
{
    bool rtake=false;
    for(auto r:mp[i])
    {
        bool take=true;
        for(auto s:r)
        {
            if(s==i) break;
            if(!take) break;
            if(!(s>="A" && s<"Z") && s!="^")
            {
                ss.insert(s);
                break;
            }
            else if(s=="^")
            {
                if(org==i||i==last)
                ss.insert(s);
                rtake=true;
                break;
            }
            else
            {
                take=dfs(s,org,r[r.size()-1],mp);
                rtake|=take;
            }
        }
    }
    return rtake;
}

int main()
{
    ifstream input("input6.txt");

    int numNonTerminals,numTerminals;
    input>>numNonTerminals>>numTerminals;
    input.ignore();

    string nonTerminalLine;
    getline(input,nonTerminalLine);
    vector<string>nonTerminals=splitString(nonTerminalLine,' ');

    string terminalLine;
    getline(input,terminalLine);
    vector<string>terminals=splitString(terminalLine,' ');

    map<string,vector<vector<string>>> mp;
    for(int i=0;i<numNonTerminals;i++)
    {
        string ruleLine;
        getline(input,ruleLine);
        vector<vector<string>> temp;
        vector<string>rules=splitString(ruleLine,',');
        for(auto j:rules)
        {
            temp.push_back(splitString(j,' '));
        }
        mp[nonTerminals[i]]=temp;
    }

    cout<<"Non Terminals: ";
    for(int i=0;i<numNonTerminals;i++)
    {
        if(i) cout<<",";
        cout<<nonTerminals[i];
    }
    cout<<"\n";

    map<string,set<string>> fmp;
    for(auto q:mp)
    {
        ss.clear();
        dfs(q.first,q.first,q.first,mp);
        for(auto g:ss) fmp[q.first].insert(g);
    }

    cout<<"FIRST(NT): ";
    for(int i=0;i<numNonTerminals;i++)
    {
        if(i) cout<<",";
        cout<<"{";
        bool first=true;
        for(auto& terminal:fmp[nonTerminals[i]])
        {
            if(!first) cout<<",";
            cout<<terminal;
            first=false;
        }
        cout<<"}";
    }
    cout<<"\n";

    map<string,set<string>> gmp;
    gmp[nonTerminals[0]].insert("$");
    int count=20;
    while(count--)
    {
        for(auto q:mp)
        {
            for(auto r:q.second)
            {
                int i;
                for(i=0;i<r.size()-1;i++)
                {
                    if(r[i]>="A" && r[i]<="Z")
                    {
                        if(!(r[i+1]>="A" && r[i+1]<="Z"))
                            gmp[r[i]].insert(r[i+1]);
                        else
                        {
                            string temp=r[i+1];
                            int j=i+1;
                            while(temp>="A" && temp<="Z")
                            {
                                if(*fmp[temp].begin()=="^")
                                {
                                    for(auto g:fmp[temp])
                                    {
                                        if(g!="^")
                                            gmp[r[i]].insert(g);
                                    }
                                    j++;
                                    if(j<r.size())
                                    {
                                        temp=r[j];
                                        if(!(temp>="A" && temp<="Z"))
                                        {
                                            gmp[r[i]].insert(temp);
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        for(auto g:gmp[q.first])
                                            gmp[r[i]].insert(g);
                                        break;
                                    }
                                }
                                else
                                {
                                    for(auto g:fmp[temp])
                                        gmp[r[i]].insert(g);
                                    break;
                                }
                            }
                        }
                    }
                }
                if(r[r.size()-1]>="A" && r[r.size()-1]<="Z")
                {
                    for(auto g:gmp[q.first]) gmp[r[i]].insert(g);
                }
            }
        }
    }

    cout<<"FOLLOW(NT): ";
    for(int i=0;i<numNonTerminals;i++)
    {
        if(i) cout<<",";
        cout<<"{";
        bool first=true;
        for(auto& terminal:gmp[nonTerminals[i]])
        {
            if(!first) cout<<",";
            cout<<terminal;
            first=false;
        }
        cout<<"}";
    }
    cout<<"\n";

    return 0;
}