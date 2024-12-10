#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(12);
    v.push_back(-2);
    v.push_back(42);
    v.push_back(-2);
    v.push_back(32);
    v.push_back(2);
    v.push_back(1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    sort(v.begin(),v.end());
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    reverse(v.begin(),v.end()-5);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}