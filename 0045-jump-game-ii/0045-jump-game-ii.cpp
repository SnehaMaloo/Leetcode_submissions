class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach=0;
        int curr=0,n=nums.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            maxreach=max(maxreach,i+nums[i]);
            if((i==curr)&&(i!=n-1))
            {
                cnt++;
                curr=maxreach;
            }
            if(i>curr)
            {
                return -1;
            }
        }
        return cnt;
    }
};