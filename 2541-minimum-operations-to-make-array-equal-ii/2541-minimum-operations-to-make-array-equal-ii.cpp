class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long int n=nums1.size();
        long long int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]>nums2[i])
            {
                int curr=nums1[i]-nums2[i];
                if(k==0||curr%k!=0)
                {
                    return -1;
                }
                else
                {
                    cnt1+=(curr/k);
                }
            }
            else if(nums1[i]<nums2[i])
            {
                int curr=nums2[i]-nums1[i];
                if(k==0||curr%k!=0)
                {
                    return -1;
                }
                else
                {
                    cnt2+=(curr/k);
                }
            }
        }
        if(cnt1==cnt2)
        {
            return cnt1;
        }
        return -1;
    }
};