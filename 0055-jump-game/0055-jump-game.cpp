class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        int curr=0,n=nums.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            maxreach=max(maxreach,i+nums[i]);
            if(i==curr)
            {
                cnt++;
                curr=maxreach;
            }
            if(i>curr)
            {
                return false;
            }
        }
        return true;
    }
};