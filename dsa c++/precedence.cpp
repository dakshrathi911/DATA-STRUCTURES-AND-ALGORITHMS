#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool prcd(char x,char y)
{
    if(x=='^'||x=='*'||x=='/'||x=='%')
    {
        if(y=='^')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(x=='+'||x=='-')
    {
        if(y=='+'||y=='-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    string infix;
    string postfix;
    stack<char>s;
    int i=0;
    while(!infix.size())
    {
        char symb;
        symb=infix[i];
        i++;
        if(symb>='a'&&symb<='z')
        {
            postfix=postfix+symb;
        }
        else
        {
            while(!s.empty()&&prcd(s.top(),symb))
            {
                char x=s.top();
                s.pop();
                
            }
        }
    }
}