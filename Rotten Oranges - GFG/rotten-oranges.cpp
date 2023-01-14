//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool ischeck(int nx,int ny,int n,int m)
    {
        if(nx>=0&&ny>=0&&nx<n&&ny<m)
        {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int cnt=0,ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ng(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    ans++;
                }
                if(grid[i][j]==1)
                {
                    ans++;
                }
            }
        }
        cnt=-1;
        while(!q.empty())
        {
            int size=q.size();
            cnt++;
            while(size!=0)
            {
                int x=q.front().first;
                int y=q.front().second;
                ans--;
                ng[x][y]=-1;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(ischeck(nx,ny,n,m)&&(grid[nx][ny]==1)&&(ng[nx][ny]==0))
                    {
                        q.push({nx,ny});
                        ng[nx][ny]=-1;
                    }
                }
                size--;
            }
        }
        return (ans==0)?cnt:-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends