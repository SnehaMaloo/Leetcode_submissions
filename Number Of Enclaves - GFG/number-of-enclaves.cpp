//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dx[4]={-1,0,1,0};
  int dy[4]={0,1,0,-1};
    int dfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[x][y]=0;
        int ans=0;
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1&&vis[nx][ny]==-1)
            {
                ans+=dfs(nx,ny,grid,vis);
            }
        }
        return ans+(grid[x][y]==1);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
                if((i==0||j==0||i==n-1||j==m-1)&&(grid[i][j]==1&&vis[i][j]==-1))
                {
                    cnt-=dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends