//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[72][105][105];
    int solve(int n, int m, vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        for(int col1=0;col1<m;col1++)
        {
            for(int col2=0;col2<m;col2++)
            {
                int sum=0;
                if(col1==col2)
                {
                    sum=grid[n-1][col1];
                }
                else
                {
                    sum+=grid[n-1][col1]+grid[n-1][col2];
                }
                dp[n-1][col1][col2]=sum;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int col1=0;col1<m;col1++)
            {
                for(int col2=0;col2<m;col2++)
                {
                    int sum=0;
                        if(col1==col2)
                        {
                            sum=grid[i][col1];
                        }
                        else
                        {
                            sum+=grid[i][col1]+grid[i][col2];
                        }
                        int ans=0;
                        for(int x=-1;x<=1;x++)
                        {
                            int nc1=col1+x;
                            for(int y=-1;y<=1;y++)
                            {
                                int nc2=col2+y;
                                if(nc1>=m || nc2>=m || nc1<0 || nc2<0)
                                {
                                    continue;
                                }
                                ans=max(ans,dp[i+1][nc1][nc2]);
                            }
                        }
                        dp[i][col1][col2]=ans+sum;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends