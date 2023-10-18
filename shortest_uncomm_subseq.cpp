// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int f(string &s,string &t,int i,int j)
{
    if(i>=s.size()) return 99999;
    if(j>=t.size()) return 1;
    int k=j;
    for(k=j;k<t.size();k++)
    {
        if(s[i]==t[k]) break;
    }
    if(k==t.size()) return 1;
    return min(f(s,t,i+1,j),1+f(s,t,i+1,j+k+1));
}
int main() {
    string s="babab";
    string t="babba";
    int l=f(s,t,0,0);
    if(l==99999) cout<<-1;
    else cout<<l;
}
