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
        sort(ivt.begin(),ivt.end(),compare);
        bool flag=false;
        if(n==0||nvt[1]<ivt[0][0])
        {
            flag=true;
            res.push_back(nvt);
        }
        for(int i=0;i<n;i++)
        {
            if(!flag&&nvt[1]<ivt[i][0])
            {
                res.push_back(nvt);
                flag=true;
            }
            if(i!=0&&ivt[i][0]<=res[res.size()-1][1])
            {
                res[res.size()-1][0]=min(ivt[i][0],res[res.size()-1][0]);
                res[res.size()-1][1]=max(ivt[i][1],res[res.size()-1][1]);
            }
            else{
                res.push_back(ivt[i]);
            }
            if(!flag&&nvt[0]<=res[res.size()-1][1])
            {
                 res[res.size()-1][0]=min(nvt[0],res[res.size()-1][0]);
                res[res.size()-1][1]=max(nvt[1],res[res.size()-1][1]);
                flag=true;
            }
        }
        if(!flag)
        {
            res.push_back(nvt);
        }
        return res;
    }
};