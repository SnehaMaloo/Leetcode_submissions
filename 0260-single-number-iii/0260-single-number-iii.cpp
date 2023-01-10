class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xor0=0;
        int i;
        for(i=0;i<n;i++)
        {
            xor0^=nums[i];
        }
        int xor1=0,xor2=0;
        int k=0;
        while((xor0&(1<<k))==0)
        {
            k++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]&(1<<(k)))
            {
                xor1^=nums[i];
            }
            else
            {
                xor2^=nums[i];
            }
        }
        vector<int>res({xor1,xor2});
        return res;
    }
};