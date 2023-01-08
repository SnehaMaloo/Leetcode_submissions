class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int cnt=0;
        int n=points.size();
        if(n==1)
        {
            return 1;
        }
        for(int i=0;i<n;i++)
        {
            unordered_map<double,int>mp;
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                if(x1-points[j][0]==0)
                {
                    mp[INT_MAX]++;
                    cnt=max(cnt,1+mp[INT_MAX]);
                }
                else
                {
                    double val=(double)((y1*(1.0)-points[j][1])/(x1-points[j][0]));
                    mp[val]++;
                    cnt=max(cnt,1+mp[val]);
                }
            }
        }
        return cnt;
    }
};