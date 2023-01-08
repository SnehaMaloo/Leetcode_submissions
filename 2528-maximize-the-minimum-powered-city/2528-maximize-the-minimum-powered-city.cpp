class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long int low=*min_element(stations.begin(),stations.end());
        long long int high=accumulate(stations.begin(),stations.end(),0LL)+k;
        long long int res=0;
        while(low<=high)
        {
            long long int mid=high-((high-low)/2);
            if(ischeck(stations,mid,k,r))
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
    
    bool ischeck(vector<int>&stations,long long int mid,int k,int r)
    {
        int n=stations.size();
        long long winsum=accumulate(stations.begin(),stations.begin()+r,0LL);
        vector<int>addition(n,0);
        for(int i=0;i<n;i++)
        {
            if(i+r<n)
            {
                winsum+=stations[i+r]+addition[i+r];
            }
            if(winsum<mid)
            {
                long long int need=mid-winsum;
                if(need>k)
                {
                    return false;
                }
                k-=need;
                winsum=mid;
                addition[min(n-1,i+r)]+=need;
            }
            if(i-r>=0)
            {
                winsum-=(stations[i-r]+addition[i-r]);
            }
        }
        return true;
    }
};