class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if((n==1)&&((k%2)==1))
        {
            return -1;
        }
        if(k>n)
        {
            return *max_element(nums.begin(),nums.end());
        }
        int i,maxele=INT_MIN;
        for(i=0;i<(k-1);i++)
        {
            maxele=max(maxele,nums[i]);
        }
        return max(maxele,nums[k]);
    }
};