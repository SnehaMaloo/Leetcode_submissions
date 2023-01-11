class Solution {
public:
    int highestfactor(int n)
    {
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(n%i==0)
            {
                ans=i;
            }
        }
        return ans;
    }
    int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }
        vector<int>arr(n+1,0);
        for(int i=2;i<=n;i++)
        {
            int x=highestfactor(i);
            if(x!=1)
            {
                arr[i]=arr[x]+arr[i/x];
            }
            else if(i%2!=0)
            {
                arr[i]=i;
            }
            else
            {
                arr[i]=arr[i/2]+2;
            }
        }
        return arr[n];
    }
};