class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<pair<int,int>>adj[n];
        int m=c.size();
        for(int i=0;i<m;i++)
        {
            int x=c[i][0];
            int y=c[i][1];
            adj[x].push_back({y,1});
             adj[y].push_back({x,0});
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        int ans=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(auto it:adj[curr])
            {
                if(!vis[it.first])
                {
                    vis[it.first]=1;
                    ans+=it.second;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};