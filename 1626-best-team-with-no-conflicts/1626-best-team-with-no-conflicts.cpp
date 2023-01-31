class Solution {
public:
    int dp[1005][1005];
    int solve(int i,int j,vector<pair<int,int>>&temp)
    {
        if(i<0)
        {
            return 0;
        }
        else if(dp[i][j+1]!=-1)
        {
            return dp[i][j+1];
        }
        int take=0,not_take=0;
        if(j==-1||temp[i].second<=temp[j].second)
        {
            take=temp[i].second+solve(i-1,i,temp);
        }
        not_take=solve(i-1,j,temp);
        return dp[i][j+1]=max(take,not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>temp;
        int n=scores.size();
        for(int i=0;i<n;i++)
        {
            temp.push_back({ages[i],scores[i]});
        }
        memset(dp,-1,sizeof(dp));
        sort(temp.begin(),temp.end());
        return solve(n-1,-1,temp);
    }
};