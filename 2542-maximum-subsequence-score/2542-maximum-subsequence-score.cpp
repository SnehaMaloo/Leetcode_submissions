class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>curr;
        int n=nums1.size(),i;
        for(i=0;i<n;i++)
        {
            int a=nums1[i];
            int b=nums2[i];
            curr.push_back({b,a});
        }
        sort(curr.begin(),curr.end());
        i=n-1;
        long long int ans=0,sum=0,j=n-1;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(j>n-k)
        {
            int a=curr[j].second;
            int b=curr[j].first;
            sum+=a;
            pq.push(a);
            j--;
        }
        while(j>=0)
        {
            pq.push(curr[j].second);
            sum+=curr[j].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*curr[j].first);
            j--;
        }
        return ans;
    }
};