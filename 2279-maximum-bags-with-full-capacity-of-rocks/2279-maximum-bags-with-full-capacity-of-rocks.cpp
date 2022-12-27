class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int aR) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=capacity.size();
        int i;
        for(i=0;i<n;i++)
        {
            pq.push(capacity[i]-rocks[i]);
        }
        int cnt=0;
        while(!pq.empty()&&aR>=pq.top())
        {
            aR-=pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};