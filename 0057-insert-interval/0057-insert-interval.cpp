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
    vector<vector<int>> insert(vector<vector<int>>& ivt, vector<int>& nvt) {
        vector<vector<int>>res;
        int n=ivt.size();
        ivt.push_back(nvt);
        sort(ivt.begin(),ivt.end(),compare);
        res.push_back(ivt[0]);
        for(int i=1;i<=n;i++)
        {
            if(ivt[i][0]<=res[res.size()-1][1])
            {
                res[res.size()-1][1]=max(res[res.size()-1][1],ivt[i][1]);
            }
            else
            {
                res.push_back(ivt[i]);
            }
        }
        return res;
    }
};