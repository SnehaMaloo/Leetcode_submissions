class Solution {
public:
    // int dp[22][2005];
    // int solve(int i,int target,vector<int>&nums,int sum)
    // {
    //     if(sum==target)
    //     {
    //         if(i<nums.size()&&nums[i]==0)
    //         {
    //             return dp[i][sum+1001]=2*solve(i+1,target,nums,sum);
    //         }
    //         return dp[i][sum+1001]=1;
    //     }
    //     if(i>=nums.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[i][sum+1001]!=-1)
    //     {
    //         return dp[i][sum+1001];
    //     }
    //     int add=solve(i+1,target,nums,sum+nums[i]);
    //     int sub=solve(i+1,target,nums,sum-nums[i]);
    //     return dp[i][sum+1001]=add+sub;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        int s=(sum+target)/2;
        if((sum+target)%2==1)return 0;
        if(sum<abs(target))
        {
            return 0;
        }
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(s+1,0));
        // 1)initialisation
        for(int col=1;col<s+1;col++){
            dp[0][col]=0;
        }
        dp[0][0]=1;
        for(int row=1;row<n+1;row++){
                dp[row][0]=1;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                // 2)choices
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    }
};