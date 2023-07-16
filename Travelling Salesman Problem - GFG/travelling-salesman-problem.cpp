//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int solve(int mask,int prev,vector<vector<int>>&cost,vector<vector<int>>&dp)
{
    int n=cost.size();
    if(mask==0)
    {
        return cost[prev][0];
    }
    else if(dp[mask][prev]!=-1)
    {
        return dp[mask][prev];
    }
    else
    {
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
               ans=min(ans,cost[prev][i]+solve(mask^(1<<i),i,cost,dp)); 
            }
        }
        return dp[mask][prev]=ans;
    }
}
int total_cost(vector<vector<int>>cost){
    int n=cost.size();
    int mask=(1<<n)-2;
    vector<vector<int>>dp(mask+1,vector<int>(n+1,-1));
    return solve(mask,0,cost,dp);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends