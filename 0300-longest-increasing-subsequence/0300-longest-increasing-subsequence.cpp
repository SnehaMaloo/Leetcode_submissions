class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            int j=it-v.begin();
            if(it!=v.end())
            {
                v[j]=nums[i];
            }
            else
            {
                v.push_back(nums[i]);
            }
        }
        return v.size();
    }
};