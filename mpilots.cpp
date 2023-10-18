// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int f(vector<int>&ass,vector<int>&cap,int i,int x)
{
    if(i==ass.size()) return 0;
    if(x==0)
    {
        return ass[i]+f(ass,cap,i+1,x+1);
    }
    else if(x==ass.size()-i)
    {
        return cap[i]+f(ass,cap,i+1,x-1);
    }
    else
    {
        return min(ass[i]+f(ass,cap,i+1,x+1),cap[i]+f(ass,cap,i+1,x-1));
    }
}
int main() {
   vector<int>ass;
   vector<int>cap;
   ass.push_back(3000);
   ass.push_back(2000);
   ass.push_back(1000);
   ass.push_back(6000);
   cap.push_back(5000);
   cap.push_back(6000);
   cap.push_back(8000);
   cap.push_back(9000);
   cout<<ass[0]+f(ass,cap,1,1);
}
