class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        int n=piles.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            sum+=piles[i];
            pq.push(piles[i]);
        }
        while(k!=0)
        {
            int curr=pq.top();
            pq.pop();
            sum-=(curr/2);
            pq.push(curr-(curr/2));
            k--;
        }
        return sum;
    }
};