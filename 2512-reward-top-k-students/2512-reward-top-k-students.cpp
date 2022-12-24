class Solution {
public:
    static bool compare(const pair<int,int>&a,const pair<int,int>&b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& rep, vector<int>& sid, int k) {
        vector<int>res;
        unordered_set<string>mpp(pf.begin(),pf.end());
        unordered_set<string>mpn(nf.begin(),nf.end());
        vector<pair<int,int>>tent;
        int n=rep.size();
        for(int i=0;i<n;i++)
        {
            int len=rep[i].length();
            int j=0;
            int cnt=0;
            while(j<len)
            {
                string temp="";
                while(j<len&&rep[i][j]!=32)
                {
                    temp+=rep[i][j];
                    j++;
                }
                if(mpp.find(temp)!=mpp.end())
                {
                    cnt+=3;
                }
                if(mpn.find(temp)!=mpn.end())
                {
                    cnt-=1;
                }
                j++;
            }
            tent.push_back({sid[i],cnt});
        }
        sort(tent.begin(),tent.end(),compare);
        for(int i=0;i<k;i++)
        {
            res.push_back(tent[i].first);
        }
        return res;
    }
};