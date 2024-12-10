#include<iostream>
#include<vector>
using namespace std;
int main()
{
    
    vector<vector<int>>v(3,vector<int>(4));
    int m=v.size();
    int n=v[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";

        }
        cout<<"\n";
    }

}