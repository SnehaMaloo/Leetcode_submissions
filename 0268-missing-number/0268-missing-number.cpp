class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor0=0,i;
        if(n%4==0)
        {
            xor0=n;
        }
        else if(n%4==1)
        {
            xor0=1;
        }
        else if(n%4==2)
        {
            xor0=n+1;
        }
        for(i=0;i<n;i++)
        {
            xor0^=nums[i];
        }
        return xor0;
    }
};