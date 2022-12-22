class Solution {
public:
    int dp[30005]={0};
    int dfs(int curr,vector<int>adj[],vector<int>&visit)
    {
        visit[curr]=0;
        if(adj[curr].size()==0)
        {
            return dp[curr]=1;
        }
        else
        {
            int ans=1;
            for(auto it:adj[curr])
            {
                if(visit[it]==-1)
                {
                    visit[it]=0;
                    ans+=dfs(it,adj,visit);
                }
            }
            return dp[curr]=ans;
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int a1=edges[i][0];
            int b1=edges[i][1];
            adj[a1].push_back(b1);
            adj[b1].push_back(a1);
        }
        vector<int>visit(n,-1);
        dfs(0,adj,visit);
        vector<int>res(n,0);
        vector<int>visit2(n,-1);
        queue<int>q;
        q.push(0);
        int cnt=0,add=0;
        visit2[0]=0;
        while(!q.empty())
        {
            int sze=q.size();
            while(sze!=0)
            {
                int curr=q.front();
                add+=cnt;
                for(auto it:adj[curr])
                {
                    if(visit2[it]==-1)
                    {
                        visit2[it]=0;
                        q.push(it);
                    }
                }
                sze--;
                q.pop();
            }
            cnt++;
        }
        res[0]=add;
        q.push(0);
        vector<int>visit3(n,-1);
        visit3[0]=0;
        while(!q.empty())
        {
            int sze=q.size();
            while(sze!=0)
            {
                int curr=q.front();
                q.pop();
                sze--;
                for(auto it:adj[curr])
                {
                    if(visit3[it]==-1)
                    {
                        res[it]=res[curr]-dp[it]+n-dp[it];
                        visit3[it]=0;
                        q.push(it);
                    }
                }
            }
        }
        return res;
    }
};