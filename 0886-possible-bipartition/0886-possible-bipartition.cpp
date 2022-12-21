class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        int i;
        int m=dislikes.size();
        for(i=0;i<m;i++)
        {
            int a1=dislikes[i][0];
            int b1=dislikes[i][1];
            adj[a1].push_back(b1);
            adj[b1].push_back(a1);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<(n+1);i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int curr=q.front();
                    q.pop();
                    for(auto it:adj[curr])
                    {
                        if(color[it]==-1)
                        {
                            color[it]=1-color[curr];
                            q.push(it);
                        }
                        else if(color[it]==color[curr])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};