
   class Solution {
public:
int dp[1005];
int rec(vector<int> &cost,int i){
  
    if(i>=cost.size()) return 0;
   if(dp[i]!=-1) return dp[i];
    int s1=cost[i]+rec(cost,i+1);
    int s2=cost[i]+rec(cost,i+2);
   
    return dp[i]=min(s1,s2);

}
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(rec(cost,0),rec(cost,1));
    }
};