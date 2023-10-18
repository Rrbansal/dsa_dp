#include<bits/stdc++.h>
#include <iostream>
using namespace std;
long long dp[2005][2005][6];
int f(vector<long long>&a,vector<long long>&b,int i,int j,int k)
{
	if(i>=a.size()) return 0;
	if(j>=b.size()) return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(a[i]==b[j]) return dp[i][j][k]=1+f(a,b,i+1,j+1,k);
	else
	{
		if(k>0)
		{
			return dp[i][j][k]=max({1+f(a,b,i+1,j+1,k-1),f(a,b,i+1,j,k),f(a,b,i,j+1,k)});
		}
		else
		{
			return dp[i][j][k]=max(f(a,b,i+1,j,k),f(a,b,i,j+1,k));

		}
	}
}
int main() {
	int n,m,k;
	cin>>n;
	cin>>m;
	cin>>k;
	vector<long long>a;
	vector<long long>b;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
	{
		long long ele;
		cin>>ele;
		a.push_back(ele);
	}
	for(int i=0;i<n;i++)
	{
		long long ele;
		cin>>ele;
		b.push_back(ele);
	}
	cout<< f(a,b,0,0,k);
}
