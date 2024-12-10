#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    char x='x';
    string s=s1+x;
    s=s+s2;
    cout<<s;
    cout<<endl<<s.size();

    return 0;
}