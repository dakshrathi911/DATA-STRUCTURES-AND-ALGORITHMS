#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    //string str1, str2;
    //cin >> str1 >> str2;
    // reverse(str1.begin(), str1.end());
    // reverse(str1.begin(), str1.begin()+4);
    // sort(str1.begin(), str1.begin()+4);
    // sort(str1.begin(), str1.end());

    // string str="abcdefgh";
    // cout<<str.substr(0,5)<<endl;
    // cout<<str.substr(2,5)<<endl;
    // cout<<str.substr(3,3)<<endl;

    string str1;
    cin>>str1;
    for(int i=0;i<=str1.size();i++)
    {

    for(int j=1;j<str1.size()-i;j++)
    {

    cout<<str1.substr(i,j)<<endl;

    }
    }

    //cout << str1;

    // cout<<str1+str2<<endl;
    // cout<<str.size();
    // operator overloading
}