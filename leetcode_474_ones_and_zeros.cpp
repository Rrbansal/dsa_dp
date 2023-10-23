#define pp pair<int,int> 
class Solution {
public:
map<int,pair<int,int>>mp;
vector<vector<vector<int>>>dp;
int f(vector<string>& strs, int m, int n,int idx)
{
    if(idx>=strs.size()) return 0;
    if(m<=0 && n<=0) return 0;
    if(dp[m][n][idx]!=-1) return dp[m][n][idx];
    int pick=-99999;
    if(mp[idx].first<=m && mp[idx].second<=n) pick=1+f(strs,m-mp[idx].first,n-mp[idx].second,idx+1);
    int nopick=f(strs,m,n,idx+1);
    return dp[m][n][idx]=max(pick,nopick);

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        dp.resize(105,vector<vector<int>>(105,vector<int>(605,-1)));
        for(int i=0;i<s;i++)
        {
            int one=0;
            int zero=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='1') one++;
                else zero++;
            }
            pair<int,int>p ={zero,one};
            mp[i]=p;
        }
        return f(strs,m,n,0);
        
    }
};
