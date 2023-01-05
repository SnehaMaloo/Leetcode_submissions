class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int cnt=1,lastmin=points[0][1];
        int n=points.size();
        for(int i=1;i<n;i++)
        {
            if(lastmin>=points[i][0])
            {
                lastmin=min(lastmin,points[i][1]);
                continue;
            }
            else
            {
                cnt++;
                lastmin=points[i][1];
            }
        }
        return cnt;
    }
};