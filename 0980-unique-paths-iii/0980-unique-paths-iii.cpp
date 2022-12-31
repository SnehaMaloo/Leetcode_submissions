class Solution {
public:
    int solve(int i,int j,int cnt,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==-1)
        {
            return 0;
        }
        else if(grid[i][j]==2)
        {
            if(cnt==0)
            {
                return 1;
            }
            return 0;
        }
        int x=grid[i][j];
        grid[i][j]=-1;
        int ans=0;
        ans+=solve(i+1,j,cnt-1,grid);
        ans+=solve(i,j+1,cnt-1,grid);
        ans+=solve(i-1,j,cnt-1,grid);
        ans+=solve(i,j-1,cnt-1,grid);
        grid[i][j]=x;
        return ans;
   }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int obstacles=0;
        int n=grid.size(),m=grid[0].size();
        int si=0,sj=0,ei=0,ej=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==-1)
                {
                    obstacles++;
                }
                else if(grid[i][j]==1)
                {
                    si=i;
                    sj=j;
                }
            }
        }       
        int ans=solve(si,sj,n*m-obstacles-1,grid);
        return ans;
    }
};