#define mod 1000000007
#define ll long long
class Solution {
public:
vector<int>dp;
int n;
ll f(string &s,int i)
{
    if(i==n) return 1;
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];
    ll ans=0;
    ll mul=1;
    if(s[i]=='*') mul=9;
    ans+=mul*f(s,i+1);
    if(i<n-1)
    {
        char next=s[i+1];
        int opts=0;
        if(s[i]=='*')
        {
            if(next=='*') opts=15;
            else if(next<='6') opts=2;
            else opts=1;
        }
        else if(s[i]<'3')
        {
            if(next=='*')
            {
                if(s[i]=='1') opts=9;
                else opts=6;
            }
            else
            {
                if(stoi(s.substr(i,2))<=26) opts=1;
            }
        }
        if(opts>0) ans+=opts*f(s,i+2);
    }
    return dp[i]=ans%mod;

}
    int numDecodings(string s) {
        n=s.size();
        dp.resize(n+1,-1);
        return f(s,0);
        
    }
};
