class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i;
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
            if(cnt%3!=0)
            {
                ans|=(1<<i);
            }
        }
        return ans;
    }
};