#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
bool prcd(char x,char y)
{
    if(x=='^'||x=='*'||x=='/'||x=='%')
    {
        if(y=='^')  return false;
        else    return true;
    }
    else
    {
        if(x=='+'||x=='-')
        {
            if(y=='+'||y=='-')
                return true;
        else
                return false;
        }
    }
}
InfixToPostfix(string infix)
{
    string postfix;
    stack<char>s;
    int i=0;
    while(i<infix.size())
    {
        char symb;
        symb=infix[i];
        i++;
        if(symb>='a'&&symb<='z')
            postfix=postfix+symb;
        else
        {
            while(!s.empty() && prcd(s.top(),symb))
            {
                char x=s.top();
                s.pop();
                postfix=postfix+x;
            }
            s.push(symb);
        }
    }
    while(!s.empty())
    {
        char x=s.top();
        s.pop();
        postfix=postfix+x;
    }
    cout<<postfix;


}
InfixToPrefix(string infix)
{
    string prefix;
    stack<char>s;
    int i=0;
    while(i<infix.size())
    {
        char symb;
        symb=infix[i];
        i++;
        if(symb>='a'&&symb<='z')
            prefix=prefix+symb;
        else
        {
            while(!s.empty() && !prcd(symb,s.top()))
            {
                char x=s.top();
                s.pop();
                prefix=prefix+x;
            }
            s.push(symb);
        }
    }
    while(!s.empty())
    {
        char x=s.top();
        s.pop();
        prefix=prefix+x;
    }
    reverse(prefix.begin(),prefix.end());
    cout<<prefix;


}
//

int main()
{
    string infix;
    cin>>infix;
    InfixToPostfix(infix);
    cout<<endl<<endl;
    InfixToPrefix(infix);

    return 0;
}