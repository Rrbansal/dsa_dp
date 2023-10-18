class Solution {
public:
int perform(int x,int y,char op)
{
    if(op=='+') return x+y;
    if(op=='-') return x-y;
    if(op=='*') return x*y;
    return 0;
}
    vector<int> diffWaysToCompute(string ex) {
        vector<int>result;
        int flag=0;

        for(int i=0;i<ex.size();i++)
        {
            if(!isdigit(ex[i]))
            {
                flag=1;
                vector<int>left=diffWaysToCompute(ex.substr(0,i));
                vector<int>right=diffWaysToCompute(ex.substr(i+1));

                for(int x:left)
                {
                    for(int y:right)
                    {
                        int val=perform(x,y,ex[i]);
                        result.push_back(val);
                    }
                }
            }
        }
        if(flag==0)
        {
            result.push_back(stoi(ex));
        }
            return result;


    }
};
