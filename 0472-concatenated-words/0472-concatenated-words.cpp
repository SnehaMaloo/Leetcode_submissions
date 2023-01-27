class Solution {
public:
    int solve(int i,string &s,unordered_set<string>&mp,vector<int>&dp)
    {
        if(i==s.length())
        {
            return 0;
        }
        else if(dp[i]!=-1)
        {
            return dp[i];
        }
        else
        {
            int ans=-31;
            for(int j=i;j<s.length();j++)
            {
                if(mp.find(s.substr(i,j-i+1))!=mp.end())
                {
                    ans=max(ans,1+solve(j+1,s,mp,dp));
                }
            }
            return dp[i]=ans;
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        int n=words.size();
        unordered_set<string>mp;
        for(int i=0;i<n;i++)
        {
            mp.insert(words[i]);
        }
        for(int i=0;i<n;i++)
        {
            int m=words[i].length();
            vector<int>dp(m,-1);
            int count=solve(0,words[i],mp,dp);
            if(count>1)
            {
                res.push_back(words[i]);
            }
        }
        //sort(res.begin(),res.end());
        return res;
    }
};