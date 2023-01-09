class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n=tasks.size(),m=workers.size();
        int low=0,high=min(n,m);
        int res=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(ischeck(tasks,workers,pills,strength,mid))
            {
                res=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
    bool ischeck(vector<int>&tasks,vector<int>&workers,int pills,int strength,int mid)
    {
        multiset<int>st(workers.begin(),workers.end());
        int cnt=0;
        for(int i=mid-1;i>=0;i--)
        {
            auto it=st.end();
            it--;
            if(*(it)>=tasks[i])
            {
                st.erase(it);
            }
            else
            {
                if(pills<=0)
                {
                    return false;
                }   
                auto itn=st.lower_bound(tasks[i]-strength);
                if(itn==st.end())
                {
                    return false;
                }
                else
                {
                    pills--;
                    st.erase(itn);
                }
            }
        }
        return true;
    }
};