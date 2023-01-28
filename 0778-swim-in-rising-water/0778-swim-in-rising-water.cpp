class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int dx[4]={1,0,0,-1};
        int dy[4]={0,1,-1,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
        vis[0][0]=grid[0][0];
        while(!q.empty())
        {
            int t=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==n-1&&y==n-1)
            {
                return t;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n&&ny<m&&nx>=0&&ny>=0&&vis[nx][ny]==false)
                {
                    vis[nx][ny]=true;
                    q.push({max(t,grid[nx][ny]),{nx,ny}});
                }
            }
        }
        return -1;
    }
};