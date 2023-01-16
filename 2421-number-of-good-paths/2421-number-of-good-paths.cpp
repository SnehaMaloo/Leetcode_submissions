class Unionfind{
    private:
    vector<int>rank,parent;
    public:
    Unionfind(int n)
    {
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }
    
    int findParent(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        else return parent[u]=findParent(parent[u]);
    }
    
    void connect(int u,int v)
    {
        int x=findParent(u);
        int y=findParent(v);
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        else if(rank[y]>rank[x])
        {
            parent[x]=y;
        }
        else
        {
            parent[y]=x;
        }
    }
    
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int>adj[n];
        int cnt=0;
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            if(vals[x]>=vals[y])
            {
                adj[x].push_back(y);
            }
            else
            {
                adj[y].push_back(x);
            }
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[vals[i]].push_back(i);
        }
        Unionfind uf(n);
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            for(auto it1:it->second)
            {
                for(auto it2:adj[it1])
                {
                    uf.connect(it1,it2);
                }
            }
            map<int,int>mp1;
            for(auto it1:it->second)
            {
                mp1[uf.findParent(it1)]++;
            }
            for(auto it2:mp1)
            {
                int size=it2.second;
                cnt+=(size*(size+1))/2;
            }
        }
        return cnt;
    }
};