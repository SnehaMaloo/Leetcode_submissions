class Solution {
public:
    bool solve(int mid,vector<int>&price,int k)
    {
        int n=price.size();
        int cnt=1,prev=price[0];
        for(int i=1;i<n;i++)
        {
            if((price[i]-prev)>=mid)
            {
                cnt++;
                prev=price[i];
            }
        }
        return cnt>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int i;
        int high=price[n-1],low=0,res=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            bool check=solve(mid,price,k);
            if(check)
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
};