class Solution {
public:
    vector<vector<int>>res;
    void dfs(int x,vector<int>&curr,vector<vector<int>>& graph,vector<int>&visit,int n)
    {
        int m=graph[x].size();
        curr.push_back(x);
        if(x==(n-1))
        {
            res.push_back(curr);
            curr.pop_back();
            return ;
        }
        for(int i=0;i<m;i++)
        {
            if(visit[graph[x][i]]!=0)
            {
                 visit[graph[x][i]]=0;
                dfs(graph[x][i],curr,graph,visit,n);
                visit[graph[x][i]]=-1;
            }
        }
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visit(n+1,-1);
        visit[0]=0;
        for(int i=0;i<graph[0].size();i++)
        {
            vector<int>curr;
            curr.push_back(0);
            visit[graph[0][i]]=0;
            dfs(graph[0][i],curr,graph,visit,n);
             visit[graph[0][i]]=-1;
        }
        return res;
    }
};