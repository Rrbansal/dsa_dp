#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>>dp;
// int f(int i,int j,vector<int>&arr)
// {
// 	if(i==j || (i+1==j)) return 0;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int ans=INT_MAX;
// 	for(int k=i+1;k<=j-1;k++)
// 	{
// 		ans=min(ans,f(i,k,arr)+f(k,j,arr)+arr[i]*arr[k]*arr[j]);
// 	}
// 	return dp[i][j]=ans;
// }
int main()
{
	vector<int>arr;
	dp.resize(1005,vector<int>(1005,0));
	arr.push_back(40);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(10);
	arr.push_back(30);
	int n=arr.size();
	for(int len=3;len<=n;len++)
	{
	    for(int i=0;i+len-1<n;i++)
	    {
	        int j=i+len-1;
	        dp[i][j]=INT_MAX;
        	for(int k=i+1;k<=j-1;k++)
        	{
        		dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
        	}
	    }
	}
	cout<<dp[0][n-1];
// 	cout<<f(0,n-1,arr);
	
	
}
