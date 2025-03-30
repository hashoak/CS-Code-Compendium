#include <bits/stdc++.h>
using namespace std;

void threeAddCode(ifstream &code)
{
    regex assign("[a-zA-Z_][a-zA-Z0-9_]* *= *[a-zA-Z0-9_]* *([+-/*] *[a-zA-Z0-9_]*)*");
    regex if_cond("if[ \t\r\n\f]*\\( *(.*) *\\) +(.*);");
    regex else_cond("else[ \t\r\n\f]+(.*);");

    string line;
    smatch match;
    int add=100;
    cout<<"------------------------\n";
    cout<<"Ref | Three Address Code\n";
    cout<<"------------------------\n";
    while(getline(code,line))
    {
        if(regex_search(line,match,if_cond))
        {
            cout<<add<<" | if "<<match.str(1)<<" goto "<<add+2<<"\n";
            cout<<++add<<" | goto "<<add+4<<"\n";
            cout<<++add<<" | "<<match.str(2)<<"\n";
            cout<<++add<<" | goto "<<add+3<<"\n";
        }
        else if(regex_search(line,match,else_cond)) cout<<add<<" | "<<match.str(1)<<"\n";
        else if(regex_search(line,match,assign)) cout<<add<<" | "<<match.str()<<"\n";
        add++;
    }
    cout<<add<<" | \n";
}

int main()
{
    ifstream input("input1.txt");
    threeAddCode(input);
    return 0;
}