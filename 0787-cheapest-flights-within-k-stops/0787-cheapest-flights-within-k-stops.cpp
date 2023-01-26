class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        dist[src]=0;
        int m=flights.size();
        for(int i=0;i<=k;i++)
        {
            vector<int>temp(dist);
            for(int j=0;j<m;j++)
            {
                int x=flights[j][0];
                int y=flights[j][1];
                int distance=flights[j][2];
                if(dist[x]!=1e9&&temp[y]>dist[x]+distance)
                {temp[y]=dist[x]+distance;}
            }
            dist=temp;
        }
        if(dist[dst]>=1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};