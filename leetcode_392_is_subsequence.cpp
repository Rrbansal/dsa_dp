class Solution {
public:
bool f(string &s, string &t,int i,int j)
{
    if(i==s.size() && j==t.size()) return true;
    if(i<=s.size()-1 && j>=t.size()) return false;
    if(s[i]==t[j]) return f(s,t,i+1,j+1);
    else return f(s,t,i,j+1);
}
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true; 
        return f(s,t,0,0);
        
    }
};
