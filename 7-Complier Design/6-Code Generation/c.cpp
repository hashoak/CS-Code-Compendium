#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if(c=='^') return 3;
    else if(c=='/' || c=='*') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ') s.erase(i,1);
        if(s[i]=='-' && (i==0 || prec(s[i-1])>=0))
        {
            s.insert(i,"( ");
            int j=i+4;
            while(s[j]=='(')
            {
                int x=1;
                for(j=j;x;j++)
                {
                    if(s[j]=='(') x++;
                    if(s[j]==')') x--;
                }
            }
            s.insert(j,")");
            i++;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(c==' ' || (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) result+=c;
        else if(c=='(') st.push('(');
        else if(c==')')
        {
            while(st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(s[i])<=prec(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}

string TACQuadruples(const string& postfix)
{
    stack<string> operands;
    int tempCount=1;

    cout<<"-------------------------------\n";
    cout<<"Ref | Op | Arg1 | Arg2 | Result\n";
    cout<<"-------------------------------\n";
    for(char c:postfix)
    {
        if(prec(c)>0)
        {
            string op2=operands.top();
            operands.pop();
            string op1=operands.top();
            operands.pop();
            operands.push("t"+to_string(tempCount));
           
            cout<<left<<setw(4)<<setfill(' ')<<tempCount-1;
            cout<<"|";
            cout<<left<<setw(4)<<setfill(' ')<<c;
            cout<<"|";
            cout<<left<<setw(6)<<setfill(' ')<<op1;
            cout<<"|";
            cout<<left<<setw(6)<<setfill(' ')<<op2;
            cout<<"|";
            cout<<operands.top()<<"\n";
            tempCount++;
        }
        else
        {
            string operand(1,c);
            operands.push(operand);
        }
    }
    return operands.top();
}

string machineInstructions(const string& postfix)
{
    stack<string> operands;
    int tempCount=0;
    string temp;

    for(char c:postfix)
    {
        if(prec(c)>0)
        {
            string op2=operands.top();
            operands.pop();
            string op1=operands.top();
            operands.pop();
            if(op1[0]!='R')
            {
                string top1=(op1!=" ")? op1:"#0";
                op1=("R"+to_string(tempCount++));
                cout<<"MOV "<<op1<<","<<top1<<"\n";
            }
            if(op2[0]!='R')
            {
                string top2=(op2!=" ")? op1:"#0";
                op2=("R"+to_string(tempCount++));
                cout<<"MOV "<<op2<<","<<top2<<"\n";
            }
            operands.push("R"+to_string(tempCount++));
            if(c=='+') cout<<"ADD ";
            else if(c=='-') cout<<"SUB ";
            else if(c=='*') cout<<"MUL ";
            else if(c=='/') cout<<"DIV ";
            cout<<operands.top()<<","<<op1<<","<<op2<<"\n";
        }
        else
        {
            string operand(1,c);
            operands.push(operand);
        }
    }
    return operands.top();
}

int main()
{
    string infix;
    cout<<"Enter the infix expression: ";
    getline(cin,infix);
    string postfix=infixToPostfix(infix);
    cout<<"Postfix Expression: "<<postfix<<"\n";

    cout<<"\nQuadruple table:\n";
    TACQuadruples(postfix);
    
    cout<<"\nMachine instructions:\n";
    machineInstructions(postfix);
    return 0;
}
