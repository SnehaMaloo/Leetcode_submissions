class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int cnt0=0,cnt1=0;
            for(int j=0;j<n;j++)
            {
                if((nums[j])&(1<<i))
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
            
            ans+=cnt0*cnt1;
        }
        return ans;
    }
};