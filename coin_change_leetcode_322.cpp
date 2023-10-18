class Solution {
public:
vector<vector<int>>dp;

int helper(vector<int>& coins, int target,int idx)
{
    if(target==0) return 0;
    if(idx==coins.size()-1)
    {
        if(target%coins[idx]==0) return target/coins[idx];
        else return 99999;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int nopick=0+helper(coins,target,idx+1);
    int take=99999;
    if(coins[idx]<=target) take=1+helper(coins,target-coins[idx],idx);
    return dp[idx][target]=min(nopick,take);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(15,vector<int>(10005,-1));
        int ans=helper(coins,amount,0);
        if(ans==99999) return -1;
        return ans;
        
    }
};
