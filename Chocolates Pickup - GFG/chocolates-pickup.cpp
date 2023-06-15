//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[72][105][105];
    int f(int i,int col1,int col2,int n,int m,vector<vector<int>>&grid)
    {
        if(i==n)
        {
            return 0;
        }
        else if(col1>=m || col2>=m ||col1<0 ||col2<0)
        {
            return 0;
        }
        else if(dp[i][col1][col2]!=-1)
        {
            return dp[i][col1][col2];
        }
        int sum=0;
        if(col1==col2)
        {
            sum+=grid[i][col1];
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
                ans=max(ans,f(i+1,nc1,nc2,n,m,grid));
            }
        }
        return dp[i][col1][col2]=ans+sum;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,m-1,n,m,grid);
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