class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int i;
        int m=INT_MIN,cnt=INT_MAX;
        for(i=0;i<n;i++)
        {
            tasks[i].push_back(i);
            m=max(tasks[i][0]+tasks[i][1],m);
        }
        auto comp=[](vector<int>a,vector<int>b)
        {
            if(a[1]==b[1])
            {
                return a[2]>b[2];
            }
            return a[1]>b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)>pq(comp);
        sort(tasks.begin(),tasks.end());
        cnt=tasks[0][0];
        int j=0;
        vector<int>res;
        while(cnt<=m)
        {
            while(j<n&&tasks[j][0]<=cnt)
            {
                pq.push(tasks[j]);
                j++;
            }
            if(!pq.empty())
            { 
                vector<int>curr=pq.top();
                cnt=max(cnt,curr[1]+cnt);
                res.push_back(curr[2]);
                pq.pop();
            }
            else if(j<n)
            {
                cnt=tasks[j][0];
            }
            else
            {
                cnt++;
            }
        }
        while(!pq.empty())
        {
             vector<int>curr=pq.top();
            res.push_back(curr[2]);
            pq.pop();
        }
        return res;
    }
};