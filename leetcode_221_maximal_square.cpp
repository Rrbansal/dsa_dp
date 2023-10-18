class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>ans;
        ans.resize(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1') ans[i][j]=1;
                else ans[i][j]=0;
            }
        }
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
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,ans[i][j]);
            }
        }
        return maxi*maxi;
        
    }
};
