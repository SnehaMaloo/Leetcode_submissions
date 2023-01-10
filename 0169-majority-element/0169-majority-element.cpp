class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=0,i;
        for(i=0;i<32;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]&(1<<i))
                {
                    cnt++;
                }
            }
            if(cnt>(n/2))
            {
                ans|=(1<<i);
            }
        }
        return ans;
    }
};