//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int x,vector<vector<int>>&points,int n,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 0;
        }
        else if(dp[i][x+1]!=-1)
        {
            return dp[i][x+1];
        }
        int sum=0;
        for(int j=0;j<3;j++)
        {
            if(j!=x)
            {
                sum=max(sum,points[i][j]+solve(i+1,j,points,n,dp));
            }
        }
        return dp[i][x+1]=sum;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(0,-1,points,n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends