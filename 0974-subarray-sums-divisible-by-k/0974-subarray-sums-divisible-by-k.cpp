class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int tot=0;
        unordered_map<int,int>mp;
        int cnt=0;
        mp[0]++;
        for(int i=0;i<n;i++)
        {
            tot+=nums[i];
            int mod=(tot%k+k)%k;
            if(mp.find(mod)!=mp.end())
            {
                cnt+=mp[mod];
            }
            mp[mod]++;
        }
        return cnt;
    }
};