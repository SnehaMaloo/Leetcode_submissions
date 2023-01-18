class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),i,maxsum=INT_MIN,curmax=0,minsum=INT_MAX,curmin=0,total=0;
        for(int i=0;i<n;i++)
        {
            curmax=max(curmax+nums[i],nums[i]);
            maxsum=max(maxsum,curmax);
            curmin=min(curmin+nums[i],nums[i]);
            minsum=min(minsum,curmin);
            total+=nums[i];
        }
        return maxsum>0?max(maxsum,total-minsum):maxsum;
    }
};