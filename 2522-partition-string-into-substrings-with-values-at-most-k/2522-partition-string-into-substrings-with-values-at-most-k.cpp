class Solution {
public:
    int solve(int i,string &s,int k,int len,vector<int>&dp)
    {
        if(i==s.length())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int num=0,ans=1e9;
        int n=s.length();
        for(int j=i;j<min(n,i+len);j++)
        {
            num=num*10+s[j]-48;
            if(num<=k)
            {
                ans=min(ans,1+solve(j+1,s,k,len,dp));
            }
            else
            {
                break;
            }
        }
        return dp[i]=ans;
    }
    int minimumPartition(string s, int k) {
        int num=k;
        int len=0;
        while(num!=0)
        {
            num/=10;
            len++;
        }
        int n=s.length();
        vector<int>dp(n+1,-1);
        int ans=solve(0,s,k,len,dp);
        return ans>=1e9?-1:ans;
    }
};