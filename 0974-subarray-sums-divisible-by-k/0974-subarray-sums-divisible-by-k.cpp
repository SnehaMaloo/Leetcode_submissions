class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int tot=0;
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            tot+=nums[i];
            if(tot%k==0)
            {
                cnt++;
            }
            if(mp.find(tot%k)!=mp.end())
            {
                cnt+=mp[tot%k];
            }
            if(mp.find(-1*(k-(tot%k)))!=mp.end())
            {
                cnt+=mp[-1*((k-(tot%k)))];
            }
            if(mp.find(k+(tot%k))!=mp.end())
            {
                cnt+=mp[k+(tot%k)];
            }
            //cout<<i<<" "<<(tot%k)<<" "<<cnt<<endl;
            mp[tot%k]++;
        }
        return cnt;
    }
};