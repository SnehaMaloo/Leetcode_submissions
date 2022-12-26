class Solution {
public:
    int solve(int lo,int hi,vector<int>&nums)
    {
        int currmax=0,prevmax=0;
        for(int i=lo;i<=hi;i++)
        {
            int temp=currmax;
            currmax=max(currmax,prevmax+nums[i]);
            prevmax=temp;
        }
        return currmax;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        return max(solve(1,n-1,nums),solve(0,n-2,nums));
    }
};