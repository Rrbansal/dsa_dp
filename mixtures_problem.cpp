#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>>dp;
int g(int i,int j,vector<int>&arr)
{
    int result=0;
    for(int m=i;m<=j;m++)
    {
        result=(result%100+arr[m]%100)%100;
    }
    return result;
}
int f(int i,int j,vector<int>&arr)
{
	if(i==j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		ans=min(ans,f(i,k,arr)+f(k+1,j,arr)+g(i,k,arr)*g(k+1,j,arr));
	}
	return dp[i][j]=ans;
}
int main()
{
	vector<int>arr;
	dp.resize(1005,vector<int>(1005,0));
	arr.push_back(40);
	arr.push_back(60);
	arr.push_back(200);
	int n=arr.size();
	for(int len=2;len<=n;len++)
	{
	    for(int i=0;i+len-1<n;i++)
	    {
	        int j=i+len-1;
	        dp[i][j]=INT_MAX;
        	for(int k=i;k<=j-1;k++)
        	{
        		dp[i][j] =min(dp[i][j] ,dp[i][k]+dp[k+1][j]+g(i,k,arr)*g(k+1,j,arr));
        	}
	    }
	}
	cout<<dp[0][n-1];
// 	cout<<f(0,n-1,arr);
	
	
}
