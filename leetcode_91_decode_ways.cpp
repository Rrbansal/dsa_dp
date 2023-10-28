class Solution {
public:
vector<int>dp;
int f(string &s,int i)
{
    if(s[i]=='0') return 0;
    if(i>=s.size()-1) return 1;
    if(dp[i]!=-1) return dp[i];
    int ans=0;
    ans+=f(s,i+1);
    if(stoi(s.substr(i,2))<=26)  ans+=f(s,i+2);
    return dp[i]=ans;
}
    int numDecodings(string s) {
        dp.resize(105,-1);
        return f(s,0);
        
    }
};
