class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        vector<pair<int,int>>adj[n];
        int m=flights.size(),i;
        for(i=0;i<m;i++)
        {
            int x=flights[i][0];
            int y=flights[i][1];
            int z=flights[i][2];
            adj[x].push_back({y,z});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});
        dist[src]=0;
        while(!pq.empty())
        {
            auto curr=pq.top();
            int stops=curr.first;
            int x=curr.second.first;
            int currdis=curr.second.second;
            pq.pop();
            if(stops>k)
            {
                continue;
            }
            else
            {
                for(auto it:adj[x])
                {
                    int y=it.first;
                    int dis=it.second;
                    if(dist[y]>dis+currdis)
                    {
                        dist[y]=dis+currdis;
                        pq.push({stops+1,{y,dist[y]}});
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};