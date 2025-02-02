#include<bits/stdc++.h>
using namespace std;

struct Variable
{
    string name;
    string type;
    int size;
    int address;
    string scope;
    int line;
};

void symbolize(vector<Variable> &symbolTable,ifstream &code)
{
    regex data_type("(void|int|short|long|long long|float|double|long double|char|wchar_t|string|bool) +");
    regex var_name("^[a-zA-Z_][a-zA-Z0-9_]*");
    regex fun_par("(void|int|short|long|long long|float|double|long double|char|wchar_t|string|bool) +([a-zA-Z_][a-zA-Z0-9_]*)");
    map<string,int> size={{"int",4},{"short",2},{"long",4},{"long long",8},{"float",4},{"double",8},{"long double",16},{"char",1},{"bool",1},{"void",0}};

    string line;
    smatch match;
    int add=100,lineNum=0;
    while(getline(code,line))
    {
        lineNum++;
        if(regex_search(line,match,data_type))
        {
            Variable var;
            var.type=match.str(1);
            line=match.suffix().str();
            if(regex_search(line,match,var_name))
            {
                var.name=match.str();
                line=match.suffix().str();
                if(regex_search(line,match,fun_par))
                {
                    var.type="function";
                    var.size=-1;
                    var.address=-1;
                    var.scope="global";
                    var.line=lineNum;
                    symbolTable.push_back(var);
                    do
                    {
                        var.name=match.str(2);
                        var.type=match.str(1);
                        var.size=size[var.type];
                        var.address=add;
                        var.scope="functional parameter";
                        var.line=lineNum;
                        symbolTable.push_back(var);
                        add+=var.size;
                        line=match.suffix().str();
                    }while(regex_search(line,match,fun_par));
                }
                else if(var.name!="main")
                {
                    var.size=size[var.type];
                    var.address=add;
                    var.scope="local";
                    var.line=lineNum;
                    symbolTable.push_back(var);
                    add+=var.size;
                }
            }
        }
    }
}

int main()
{
    ifstream code("input1.txt");
    vector<Variable> symbolTable;
    symbolize(symbolTable,code);

    cout<<"Name\tType\t    Size    Address\tScope\t\t\tLine no\n";
    for(auto i:symbolTable)
    {
        cout<<left<<setw(8)<<setfill(' ')<<i.name;
        cout<<left<<setw(12)<<setfill(' ')<<i.type;
        cout<<left<<setw(8)<<setfill(' ')<<i.size;
        cout<<left<<setw(12)<<setfill(' ')<<i.address;
        cout<<left<<setw(24)<<setfill(' ')<<i.scope;
        cout<<i.line<<"\n";
    }
    cout<<"\n";
    code.close();
    return 0;
}
