class Solution {
public:
    int countSquares(vector<vector<int>>& ans) {
        int n=ans.size();
        int m=ans[0].size();
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(ans[i][j]!=0)
                {
                    ans[i][j]=min({ans[i-1][j],ans[i][j-1],ans[i-1][j-1]})+1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               count+=ans[i][j];
            }
        }
        return count;
        
    }
};
