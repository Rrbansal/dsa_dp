// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>>dp;
int main() {
    dp.resize(10,vector<int>(10,0));
    string s="gfabac";
    string t="abac";
    for(int i=s.size()-1;i>=0;i--)
    {
        for(int j=t.size()-1;j>=0;j--)
        {
            if(s[i]==t[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<t.size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int index=dp[0][0];
    int i=s.size()-1;
    int j=t.size()-1;
    string ans(index,0);
    while(i>=0 && j>=0)
    {
        if(s[i]==t[j])
        {
            ans[index-1]=s[i];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
        cout<<i<<j<<" ";
    }
    cout<<ans;
   
}
