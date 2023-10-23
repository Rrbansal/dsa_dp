class Solution {
public:
vector<vector<int>>dp;
int f(string &s,string &t,int i,int j)
{
    if(i>=s.size()) return 0;
    if(j>=t.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j]=1+f(s,t,i+1,j+1);
    else return dp[i][j]=max(f(s,t,i+1,j),f(s,t,i,j+1));
}
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,-1));
        return f(text1,text2,0,0);
        
    }
};
