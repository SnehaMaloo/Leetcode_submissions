class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>dp(n);
        sort(nums.begin(),nums.end());
        dp[0].first=nums[0];
        dp[0].second=0;
        pair<int,int>prev=dp[0];
        for(int i=1;i<n;i++)
        {
            pair<int,int>tmp;
            if(nums[i-1]==nums[i]-1)
            {
                tmp={nums[i]+prev.second,max(prev.first,prev.second)};
            }
            else if(nums[i-1]==nums[i])
            {
                tmp={nums[i]+prev.first,prev.second};
            }
            else
            {
                tmp={max(nums[i]+prev.second,nums[i]+prev.first),max(prev.second,prev.first)};
            }
            dp[i]=tmp;
            prev=tmp;
            cout<<nums[i]<<" "<<prev.first<<" "<<prev.second<<endl;
        }
        return max(prev.first,prev.second);
    }
};