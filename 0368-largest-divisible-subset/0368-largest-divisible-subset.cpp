class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n,vector<int>(2,1));
        int len=0;
        for(int i=n-1;i>=0;i--)
        {
            dp[i][1]=i;
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]%nums[i]==0)
                {
                    if(dp[i][0]<1+dp[j][0])
                    {
                        dp[i][0]=1+dp[j][0];
                        dp[i][1]=j;
                    }
                }
            }
            len=max(len,dp[i][0]);
        }
        int j=0;
        while(j<n&&dp[j][0]!=len)
        {
            j++;
        }
        while(dp[j][1]!=j)
        {
            res.push_back(nums[j]);
            j=dp[j][1];
        }
        res.push_back(nums[j]);
        return res;
    }
};