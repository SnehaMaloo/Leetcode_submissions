class Solution {
public:
    int divide(int dd, int ds) {
        long long int cnt=0;
        long long int i;
        long long int ans=0;
        int sign=(dd>0)^(ds>0);
        long long td=dd<0?(-1*1ll*dd):dd;
        long long ts=ds<0?(-1*1ll*ds):ds;
        for(i=31;i>=0;i--)
        {
            if((cnt+((ts*1LL)<<i))<=td)
            {
                cnt+=ts<<i;
                ans+=(1LL<<i);
            }
        }
        if(sign)
        {
            ans=ans*(-1);
        }
        if(ans<INT_MIN)
        {
            return INT_MIN;
        }
        else if(ans>INT_MAX)
        {
            return INT_MAX;
        }
        return ans;
    }
};