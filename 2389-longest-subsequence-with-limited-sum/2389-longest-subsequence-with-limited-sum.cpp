class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>qp;
        int n=queries.size(),i;
        for(i=0;i<n;i++)
        {
            qp.push_back({queries[i],i});
        }
        sort(qp.begin(),qp.end());
        vector<int>res(n,0);
        int sum=0;
        i=0;
        for(int j=0;j<n;j++)
        {
            while(i<nums.size()&&sum<=qp[j].first)
            {
                sum+=nums[i];
                i++;
            }
            if((i==nums.size())&&sum<=qp[j].first)
            {
                res[qp[j].second]=i;
            }
            else {res[qp[j].second]=(i-1);}
        }
        return res;
    }
};