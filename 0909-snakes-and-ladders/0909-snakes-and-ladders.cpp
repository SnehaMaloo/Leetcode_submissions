class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int i=n-1,j=0,index=1;
        bool ok=true;
        vector<int>cells(n*n+1,0);
        while(index<=n*n)
        {
            cells[index++]=board[i][j];
            if(ok)
            {
                if(j==n-1)
                {
                    i--;
                    ok=false;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if(j==0)
                {
                    i--;
                    ok=true;
                }
                else
                {
                    j--;
                }
            }
        }
        queue<int>q;
        vector<int>vis(n*n+1,-1);
        q.push(1);
        int cnt=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int curr=q.front();
                q.pop();
                vis[curr]=0;
                if(curr==n*n)
                {
                    return cnt;
                }
                for(int k=1;k<=6;k++)
                {
                    if(curr+k>n*n)
                    {
                        break;
                    }
                    else
                    {
                        int dest=cells[curr+k]>-1?cells[curr+k]:curr+k;
                        if(vis[dest]==-1)
                        {
                            q.push(dest);
                            vis[dest]=0;
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};