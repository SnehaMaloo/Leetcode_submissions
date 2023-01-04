class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>mp;
        int i,cnt=0;
        for(i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int x=it->second;
            if(x==1)
            {
                return -1;
            }
            else
            {
                cnt+=(x+2)/3;
            }
        }
        return cnt;
    }
};