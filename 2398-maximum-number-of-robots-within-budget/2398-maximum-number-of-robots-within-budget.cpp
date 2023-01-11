class Solution {
public:
    int maximumRobots(vector<int>& cT, vector<int>& rC, long long budget) {
        int n=cT.size();
        int i;
        int lo=0,hi=n,res=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(ischeck(cT,rC,budget,mid))
            {
                lo=mid+1;
                res=mid;
            }
            else
            {
                hi=mid-1;
            }
        }
        return res;
    }
    bool ischeck(vector<int>&cT,vector<int>&rC,long long budget,int mid)
    {
        long long int i=0,j=0,sum=0,n=cT.size();
        deque<int>q;
        while(j<n)
        {
            sum+=rC[j];
            while(!q.empty()&&cT[q.back()]<cT[j])
            {
                q.pop_back();
            }
            q.push_back(j);
            if(j-i+1<mid)
            {
                j++;
            }
            else
            {
                if((cT[q.front()]+(long long int)mid*sum)<=budget)
                {
                    return true;
                }
                if(q.front()==i)
                {
                    q.pop_front();
                }
                sum-=rC[i];
                i++;
                j++;
            }
        }
        return false;
    }
};