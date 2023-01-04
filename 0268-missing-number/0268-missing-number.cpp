class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        if(n%4==0)
        {
            a=n;
        }
        else if(n%4==1)
        {
            a=1;
        }
        else if(n%4==2)
        {
            a=n+1;
        }
        for(int i=0;i<n;i++)
        {
            a^=nums[i];
        }
        return a;
    }
};