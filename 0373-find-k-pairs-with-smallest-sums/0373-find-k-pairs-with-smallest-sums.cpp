class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        auto comp=[&nums1,&nums2](pair<int,int>a,pair<int,int>b)
        {
            int i1=a.first;
            int i2=b.first;
            int j1=a.second;
            int j2=b.second;
            return (nums1[i1]+nums2[j1])>(nums1[i2]+nums2[j2]);
        };
        int n=nums1.size(),m=nums2.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);
        pq.push({0,0});
        while(((k--)>0)&&(pq.size()))
        {
            int i1=pq.top().first;
            int j1=pq.top().second;
            res.push_back({nums1[i1],nums2[j1]});
            pq.pop();
            if(i1<(n-1))
            {
                pq.push({i1+1,j1});
            }
            if((i1==0)&&(j1<(m-1)))
            {
                pq.push({i1,j1+1});
            }
        }
        return res;
    }
};