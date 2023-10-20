class Solution {
public:
int n;
vector<int>dp;
vector<vector<int>>job;
int f(vector<int>& startTime,int i)
{
	if(i>=n) return 0;
	if(dp[i]!=-1) return dp[i];
	int index=lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
	int pick=job[i][2]+f(startTime,index);
	int notpick=f(startTime,i+1);
	return dp[i]=max(pick,notpick);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
			n=startTime.size();
			dp.resize(n,-1);
			for(int i=0;i<n;i++)
			{
				job.push_back({startTime[i],endTime[i],profit[i]});
			}
			sort(startTime.begin(),startTime.end());
			sort(job.begin(),job.end());
			return f(startTime,0);
        
    }
};
