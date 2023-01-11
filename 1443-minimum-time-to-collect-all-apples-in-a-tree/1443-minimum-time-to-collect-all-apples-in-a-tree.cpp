class Solution {
public:
    int dfs(int i,int n,vector<int>adj[],vector<bool>&hA,vector<int>&visit)
    {
        int cnt=0;
        visit[i]=0;
        for(auto it:adj[i])
        {
            if(visit[it]==-1)
            cnt+=dfs(it,n,adj,hA,visit);
        }
       // cout<<cnt<<" "<<i<<endl;
        return (cnt!=0)?(2*(i!=0)+cnt):(hA[i]&&(i!=0))*2;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hA) {
        vector<int>adj[n];
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visit(n,-1);
        return dfs(0,n,adj,hA,visit);
    }
};