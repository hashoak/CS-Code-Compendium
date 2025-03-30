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

string TACInstructions(const string& postfix)
{
    stack<string> operands;
    int tempCount=1;

    for(char c:postfix)
    {
        if(prec(c)>0)
        {
            string op2=operands.top();
            operands.pop();
            string op1=operands.top();
            operands.pop();
            operands.push("t"+to_string(tempCount++));
            cout<<operands.top()<<" = "<<op1<<" "<<c<<" "<<op2<<"\n";
        }
        else
        {
            string operand(1,c);
            operands.push(operand);
        }
    }
    return operands.top();
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
           
            cout<<left<<setw(4)<<setfill(' ')<<tempCount;
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

string TACTriples(const string& postfix)
{
    stack<string> operands;
    int tempCount=1;

    cout<<"----------------------\n";
    cout<<"Ref | Op | Arg1 | Arg2\n";
    cout<<"----------------------\n";
    for(char c:postfix)
    {
        if(prec(c)>0)
        {
            string op2=operands.top();
            operands.pop();
            string op1=operands.top();
            operands.pop();
            cout<<left<<setw(4)<<setfill(' ')<<tempCount;
            cout<<"|";
            cout<<left<<setw(4)<<setfill(' ')<<c;
            cout<<"|";
            cout<<left<<setw(6)<<setfill(' ')<<op1;
            cout<<"|";
            cout<<op2<<"\n";
            operands.push("("+to_string(tempCount)+")");
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

int main()
{
    string infix;
    cout<<"Enter the infix expression: ";
    getline(cin,infix);
    string postfix=infixToPostfix(infix);

    cout<<"Three Address Code: \n";
    cout<<"Result: "<<TACInstructions(postfix)<<"\n\n";

    cout<<"Quadruples: \n";
    cout<<"Result: "<<TACQuadruples(postfix)<<"\n\n";

    cout<<"Triples: \n";
    cout<<"Result: "<<TACTriples(postfix)<<"\n\n";
    
    return 0;
}
