class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            adj[i]=rooms[i];
        }
        int cnt=0;
        queue<int>q;
        q.push(0);
        vector<int>visit(n,-1);
        visit[0]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[curr])
            {
                if(visit[it]==-1)
                {
                    visit[it]=0;
                    q.push(it);
                }
            }
        }
        if(cnt==n)
        {
            return true;
        }
        return false;
    }
};