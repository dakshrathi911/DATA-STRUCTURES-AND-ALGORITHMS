#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<char>s;
    s.push('K');
    s.push('J');
    s.push('I');
    s.push('H');
    s.push('G');
    s.push('F');
    s.push('E');
    s.push('D');
    s.push('C');
    s.push('B');
    s.push('A');

   while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}