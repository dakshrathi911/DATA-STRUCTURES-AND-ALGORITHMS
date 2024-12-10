/*
#include<iostream>
#include<stack>
//#include<string>
using namespace std;
int main()
{
    stack<char>s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    s.push('F');
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
    }
    return 0;
}
*/
/*
#include<iostream>
#include<stack>
#include<string> //last element is not null character
using namespace std;
int main()
{
    string s;
    cin>>s;
    cout<<s;
    return 0;
}
*/
/*
#include<iostream>
#include<stack>
#include<string> //last element is not null character
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string s=s1+" ";
    s=s+s2;
    cout<<s;
    return 0;
}
*/
/*
#include<iostream>
#include<stack>
#include<string> //last element is not null character
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    char x='*';
    string s=s1+x;
    s=s+s2;
    cout<<s;
    return 0;
}
*/
/*
#include<iostream>
#include<stack>
#include<string> //last element is not null character
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    char x='*';
    string s=s1+x;
    s=s+s2;
    cout<<s;
    cout<<endl<<s.size();
    return 0;
}
*/
#include<iostream>
#include<stack>
#include<string> 
#include<algorithm>
using namespace std;
bool prcd(char x,char y)
{
    if(x=='('||y==')')
    return false;
    else if(y==')')
        return true;
    else{
    if(x=='^' ||x=='*' || x=='/' || x=='%')
    {
        if(y=='^')
        return false;
        else
        return true; 
    }
    else{
        if(x=='+'||x=='-')
        {
            if(y=='+' || y=='-')
            return true;
            else
            return false;
        }
    }
    }
}
void InfixToPostfix(string infix)
{
    string postfix;
    stack<char>s;
    int i=0;
    while(i<infix.size())
    {
        char symb;
        symb=infix[i];
        i++;
        if((symb>='a' && symb<='z') || (symb>='A' && symb<='Z') || (symb>='0' && symb<='9'))
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
    while (!s.empty())
    {
        if(s.top()=='(' || s.top()==')')
        {
            s.pop();
        }
        else
        {
        char x=s.top();
        s.pop();
        postfix=postfix+x;
        }
    }

    cout<<postfix;
}
//
void InfixToPrefix(string infix)
{
    string prefix;
    stack<char>s;
    int i=0;
    reverse(infix.begin(),infix.end());
    while(i<infix.size())
    {
        char symb;
        symb=infix[i];
        i++;
        if((symb>='a' && symb<='z') || (symb>='A' && symb<='Z') || (symb>='0' && symb<='9'))
            prefix=prefix+symb;
        else
        {
            while(!s.empty() && !prcd(symb,s.top()))
            {
                if(s.top()=='(' || s.top()==')')
                {
                    s.pop();
                }
                else
                {
                char x=s.top();
                s.pop();
                prefix=prefix+x;
                }
            }
            s.push(symb);
        }
    }
    while (!s.empty())
    {
        if(s.top()=='('|| s.top()==')')
        {
            s.pop();
        }
        else{
        char x=s.top();
        s.pop();
        prefix=prefix+x;
        }
    }
    reverse(prefix.begin(),prefix.end());
    cout<<prefix;
}
/*/
int main()
{
    string infix;
    cin>>infix;
    InfixToPostfix(infix);
    cout<<endl;
    InfixToPrefix(infix);
    return 0;
}