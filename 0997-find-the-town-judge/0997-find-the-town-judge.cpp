class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,pair<int,int>>mp;
        int m=trust.size();
        int i,idx=-1;
        if(m==0&&n==1)
        {
            return n;
        }
        for(int i=0;i<m;i++)
        {
            int x=trust[i][0];
            int y=trust[i][1];
            mp[x].first++;
            mp[y].second++;
        }
        for(auto it:mp)
        {
            auto it1=it.second;
            if(it1.first==0&&it1.second==n-1)
            {
                idx=(it.first);
            }
        }
        return idx;
    }
};