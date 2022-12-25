class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(),i;
       vector<int>dp(n+2,0);
        dp[0]=0;
        dp[1]=0;
        for(i=2;i<=n;i++)
        {
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};