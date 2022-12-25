class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long int low=1,high=INT_MAX,res;
        while(low+1<high)
        {
            long long int mid=low+(high-low)/2;
            if(check(d1,d2,u1,u2,mid))
            {
                high=mid;
                res=mid;
            }
            else
            {
                low=mid;
            }
        }
        return res;
    }
    bool check(long long int d1,long long int d2,long long int u1,long long int u2,long long int x)
    {
        long long int A=x/d1;
        long long int B=x/d2;
        long long int A_=x-A;
        long long int B_=x-B;
        long long int AIB=x/lcm(d1,d2);
        long long int AUB=A+B-AIB;
        long long int AIB_=x-AUB;
        long long int needA=(A_-AIB_)>=u1?0:(u1-(A_-AIB_));
        long long int needB=(B_-AIB_)>=u2?0:(u2-(B_-AIB_));
        return (AIB_>=(needA+needB));
    }
};