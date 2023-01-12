class Solution {
public:
    vector<int> solve(int i,int n,vector<int>adj[],string &labels,vector<int>&ans,vector<int>&visit)
    {
        vector<int>res(26,0);
        for(auto it:adj[i])
        {
            if(visit[it]==-1)
            {
                visit[it]=0;
                vector<int>temp(26,0);
                 temp=solve(it,n,adj,labels,ans,visit);
                ans[it]=temp[labels[it]-'a'];
                for(int j=0;j<26;j++)
                {
                    res[j]+=temp[j];
                }
            }
        }
        res[labels[i]-'a']++;
        return res;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string &labels) {
        vector<int>ans(n,0);
        vector<int>adj[n];
        int i;
        int m=edges.size();
        for(i=0;i<m;i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>visit(n,-1);
        for(int i=0;i<n;i++)
        {
            if(visit[i]==-1)
            {
                visit[i]=0;
                vector<int>res=solve(i,n,adj,labels,ans,visit);
                ans[i]=res[labels[i]-'a'];
            }
        }
        return ans;
    }
};