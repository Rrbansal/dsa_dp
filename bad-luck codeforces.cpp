#include <iostream>
#include<cstring>
using namespace std;
#define ld long double
ld dp[105][105][105];
double fr(int r,int s,int p)
{
    if(r==0) return 0;
    if(s==0) return 0;
    if(p==0) return 1;
    if(dp[r][s][p]>-0.9) return dp[r][s][p];
    ld total=(r*s)+(s*p)+(p*r);
    ld result=0.0;
    result+=fr(r,s-1,p)*((r*s)/total);
    result+=fr(r,s,p-1)*((p*s)/total);
    result+=fr(r-1,s,p)*((r*p)/total);
    return dp[r][s][p]=result;

}
double fs(int r,int s,int p)
{
    if(r==0) return 1;
    if(s==0) return 0;
    if(p==0) return 0;
    if(dp[r][s][p]>-0.9) return dp[r][s][p];
    ld total=(r*s)+(s*p)+(p*r);
    ld result=0.0;
    result+=fs(r,s-1,p)*((r*s)/total);
    result+=fs(r,s,p-1)*((p*s)/total);
    result+=fs(r-1,s,p)*((r*p)/total);
    return dp[r][s][p]=result;

}
double fp(int r,int s,int p)
{
    if(r==0) return 0;
    if(s==0) return 1;
    if(p==0) return 0;
    if(dp[r][s][p]>-0.9) return dp[r][s][p];
    ld total=(r*s)+(s*p)+(p*r);
    ld result=0.0;
    result+=fp(r,s-1,p)*((r*s)/total);
    result+=fp(r,s,p-1)*((p*s)/total);
    result+=fp(r-1,s,p)*((r*p)/total);
    return dp[r][s][p]=result;

}
int main() {
    memset(dp,-1,sizeof dp);
    cout<<fr(2,2,2);
    cout<<fs(2,2,2);
    cout<<fp(2,2,2);
}
