#define ll long long int
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<ll>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++)
        {
            ll start=max(0,i-ranges[i]);
            ll end=min(n,i+ranges[i]);
            for(int j=start;j<end;j++)
            {
                dp[end]=min(dp[end],dp[j]+1);
            }
        }
        return dp[n]==INT_MAX?-1:dp[n];
        
    }
};
