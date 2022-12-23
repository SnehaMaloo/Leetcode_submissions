class Solution {
public:
    int dp[2][5001];
    int solve(int i,bool ok,vector<int>&prices)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[ok][i]!=-1)
        {
            return dp[ok][i];
        }
        int notdone=solve(i+1,ok,prices);
        int bought=0;
        int sell=0;
        if(ok)
        {
            bought=-prices[i]+solve(i+1,!ok,prices);
        }
        else
        {
            sell=prices[i]+solve(i+2,!ok,prices);
        }
        return dp[ok][i]=max(notdone,max(bought,sell));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,true,prices);
    }
};