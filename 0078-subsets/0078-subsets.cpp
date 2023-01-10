class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        int m=1<<n;
        int i;
        for(i=0;i<m;i++)
        {
            int num=i;
            int j=0;
            vector<int>curr;
            while(num!=0)
            {
                if(num&1)
                {
                    curr.push_back(nums[j]);
                }
                j++;
                num=num>>1;
            }
            res.push_back(curr);
        }
        return res;
    }
};