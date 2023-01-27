class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>temp;
        int M=1000000007;
        for(int i=0;i<n;i++)
        {
            temp.push_back({efficiency[i],speed[i]});
        }
        sort(temp.begin(),temp.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long sum=0,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=temp[i].second;
            pq.push({temp[i].second,temp[i].first});
            if(pq.size()>k)
            {
                sum-=pq.top().first;
                pq.pop();
            }
            ans=max(ans,(sum*temp[i].first));
        }
        return ans%M;
    }
};