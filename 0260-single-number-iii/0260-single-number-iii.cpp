class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xor_0=0;
        for(int i=0;i<n;i++)
        {
            xor_0^=nums[i];
        }
        int i=0;
        while((xor_0&(1<<i))==0)
        {
            i++;
        }
        int xor_1=0,xor_2=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]&(1<<(i)))
            {
                xor_1^=nums[j];
            }
            else
            {
                xor_2^=nums[j];
            }
        }
        vector<int>res({xor_1,xor_2});
        return res;
    }
};