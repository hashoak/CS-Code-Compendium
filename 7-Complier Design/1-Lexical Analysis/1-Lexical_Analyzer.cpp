#include<bits/stdc++.h>
using namespace std;

void lexicalAnalysis(ifstream &code)
{
    regex var_regex("[a-zA-Z_][a-zA-Z0-9_]*");
    regex lit_regex("\".*?\"");
    regex op_regex("=|[+-/*%!=]=?|&[&=]|\\|[|=]|\\^[|=]|<<=|>>=|<<|>>");
    regex const_regex("[+-]?(0x[0-9a-fA-F]+|0[0-7]*|[1-9][0-9]*)");
    regex kw_regex("main|printf|auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while");
    regex delim_regex("\\(|\\)|\\[|\\]|\\{|\\}|;|,");
    regex comment_regex("//.*|/\\*.*?\\*/");

    set<string> var_list;
    set<string> lit_list;
    set<string> op_list;
    set<string> const_list;
    set<string> kw_list;
    set<string> delim_list;
    set<string> comment_list;

    string line;
    smatch match;
    while (getline(code,line))
    {
        while(1)
        {
            if(regex_search(line,match,comment_regex)) comment_list.insert("\""+match.str()+"\"");
            else if(regex_search(line,match,kw_regex)) kw_list.insert(match.str());
            else if(regex_search(line,match,lit_regex)) lit_list.insert(match.str());
            else if(regex_search(line,match,var_regex)) var_list.insert(match.str());
            else if(regex_search(line,match,op_regex)) op_list.insert(match.str());
            else if(regex_search(line,match,const_regex)) const_list.insert(match.str());
            else if(regex_search(line,match,delim_regex)) delim_list.insert(match.str());
            else break;
            line.erase(line.find(match.str()),match.length());
        }
    }

    cout<<"Lexeme of keywords: ";
    for(string i:kw_list) cout<<i<<" ";
    cout<<"\nLexeme of variables: ";
    for(string i:var_list) cout<<i<<" ";
    cout<<"\nLexeme of literals: ";
    for(string i:lit_list) cout<<i<<" ";
    cout<<"\nLexeme of operators: ";
    for(string i:op_list) cout<<i<<" ";
    cout<<"\nLexeme of constants: ";
    for(string i:const_list) cout<<i<<" ";
    cout<<"\nLexeme of special symbols and delimiters: ";
    for(string i:delim_list) cout<<i<<" ";
    cout<<"\nNon-tokens(comments): ";
    for(string i:comment_list) cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    ifstream code("input1.txt");
    lexicalAnalysis(code);
    return 0;
}
