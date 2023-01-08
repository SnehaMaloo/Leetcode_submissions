class Solution {
public:
    int dp[1002][1002][2];
    int solve(int idx,int prev,vector<int>&nums,bool ok)
    {
        if(idx==nums.size())
        {
            return 0;
        }
        if(dp[idx][prev+1][ok]!=-1)
        {
            return dp[idx][prev+1][ok];
        }
        if(prev==-1)
        {
            return dp[idx][prev+1][ok]=max(solve(idx+1,idx,nums,ok),solve(idx+1,prev,nums,ok));
        }
        else if(ok)
        {
            if((nums[idx]-nums[prev])>0)
            {
                return dp[idx][prev+1][ok]=max(1+solve(idx+1,idx,nums,!ok),solve(idx+1,prev,nums,ok));
            }
            return dp[idx][prev+1][ok]=solve(idx+1,prev,nums,ok);
        }
        else
        {
             if((nums[idx]-nums[prev])<0)
            {
                return dp[idx][prev+1][ok]=max(1+solve(idx+1,idx,nums,!ok),solve(idx+1,prev,nums,ok));
            }
            return dp[idx][prev+1][ok]=solve(idx+1,prev,nums,ok);
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        memset(dp,-1,sizeof(dp));
        return max(1+solve(0,prev,nums,true),1+solve(0,prev,nums,false));
    }
};