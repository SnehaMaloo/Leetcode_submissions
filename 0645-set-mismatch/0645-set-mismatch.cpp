class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        int i,xor11=0;
        for(int i=0;i<n;i++)
        {
            xor11^=(i+1)^nums[i];
        }
        int bit=xor11&(~(xor11-1));
        int xor_0=0,xor_1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&bit)
            {
                xor_0^=nums[i];
            }
            else
            {
                xor_1^=nums[i];
            }
            if((i+1)&(bit))
            {
                xor_0^=(i+1);
            }
            else
            {
                xor_1^=(i+1);
            }
        }
        for(int i=0;i<n;i++)
        {
            if((xor_0^(nums[i]))==0)
            {
                res.push_back(xor_0);
                res.push_back(xor_1);
                return res;
            }
        }
        res.push_back(xor_1);
        res.push_back(xor_0);
        return res;
    }
};