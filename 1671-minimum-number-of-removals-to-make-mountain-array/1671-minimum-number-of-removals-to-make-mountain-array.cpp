class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp,lis(n,0),lds(n,0);
        int i;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
            int j=it-temp.begin();
            if(it!=temp.end())
            {
                temp[j]=nums[i];
            }
            else
            {
                temp.push_back(nums[i]);
            }
            lis[i]=temp.size();
        }
        vector<int>ntemp;
        for(int i=n-1;i>=0;i--)
        {
            auto it=lower_bound(ntemp.begin(),ntemp.end(),nums[i]);
            int j=it-ntemp.begin();
            if(it!=ntemp.end())
            {
                ntemp[j]=nums[i];
            }
            else
            {
                ntemp.push_back(nums[i]);
            }
            lds[i]=ntemp.size();
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]>=2&&lds[i]>=2)
            {cnt=max(cnt,lis[i]+lds[i]-1);}
        }
        return n-cnt;
    }
};