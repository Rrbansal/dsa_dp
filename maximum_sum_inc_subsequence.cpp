//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    
	    vector<int>dp(n);
	    for(int i=0;i<n;i++) dp[i]=arr[i];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[i],dp[j]+arr[i]);
	            }
	        }
	    }
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dp[i]);
	    }
	    return maxi;
	}  
};
