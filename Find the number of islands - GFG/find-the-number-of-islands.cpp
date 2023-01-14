//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool ischeck(int nx,int ny,int n,int m)
    {
        if(nx>=0&&nx<n&&ny>=0&&ny<m)
        {
            return true;
        }
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        int i,j;
        int n=grid.size(),m=grid[0].size();
        int dx[8]={1,1,-1,-1,0,0,1,-1};
        int dy[8]={1,-1,-1,1,1,-1,0,0};
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        grid[x][y]='&';
                        q.pop();
                        for(int k=0;k<8;k++)
                        {
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(ischeck(nx,ny,n,m)&&grid[nx][ny]=='1')
                            {
                                q.push({nx,ny});
                                grid[nx][ny]='&';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends