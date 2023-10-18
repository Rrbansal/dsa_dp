class Solution
{
  public:
  int dp[1005][1005][2];
  int f(int n,int k,int last)
  {
      if(n==0) return 0;
      if(n==1)
      {
          if(k==0) return 1;
          else return 0;
      }
      if(dp[n][k][last]!=-1) return dp[n][k][last] %1000000007;
      if(last==1)
      {
          return dp[n][k][last]=(f(n-1,k-1,1)+f(n-1,k,0))%1000000007;
      }
      else
      {
          return dp[n][k][last]=(f(n-1,k,1)+f(n-1,k,0))%1000000007;
      }
  }
    int countStrings(int n, int k)
    {
        memset(dp,-1,sizeof dp);
        return (f(n,k,1)+f(n,k,0))%1000000007;
    }
 
};
