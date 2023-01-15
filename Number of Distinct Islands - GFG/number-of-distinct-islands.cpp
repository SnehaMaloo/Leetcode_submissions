//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,+1};
    void dfs(int i,int j,int x,int y,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m,vector<pair<int,int>>&curr)
    {
        curr.push_back({i-x,j-y});
        vis[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1&&vis[nx][ny]==-1)
            {
                dfs(nx,ny,x,y,grid,vis,n,m,curr);
            }
        }
        return ;
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&vis[i][j]==-1)
                {
                    vector<pair<int,int>>curr;
                    dfs(i,j,i,j,grid,vis,n,m,curr);
                    st.insert(curr);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends