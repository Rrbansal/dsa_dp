class Solution {
public:
vector<int>dp;
unordered_set<string>st;
bool f(string s,int i){
    if(i==s.size()) return true;
    if(dp[i]!=-1) return dp[i];
    string temp;
    for(int j=i;j<s.size();j++)
    {
        temp+=s[j];
        if(st.find(temp)!=st.end())
        {
            if(f(s,j+1)) return dp[i]=true;
        }

    }
    return dp[i]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(305,-1);
        for(int i=0;i<wordDict.size();i++) st.insert(wordDict[i]);
        return f(s,0);
        
    }
};
