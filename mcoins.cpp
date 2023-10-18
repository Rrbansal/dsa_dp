// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int>dp;
int main() {
   int k=2,l=3;
   dp.resize(100,0);
   dp[1]=1;
   dp[k]=1;
   dp[l]=1;
   for(int i=2;i<=50;i++)
   {
       if(i==k || i==l) continue;
       dp[i]=!(dp[i-1] && ((i-k>=1)?dp[i-k]:1) && ((i-l>=1)?dp[i-l]:1));
   }
   for(int i=1;i<=50;i++)
   {
       if(dp[i]==1) cout<<i<<"a";
       else cout<<i<<"b";
       cout<<endl;
   }
}
