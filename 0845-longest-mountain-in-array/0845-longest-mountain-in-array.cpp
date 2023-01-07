class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
        {
            return 0;
        }
        int i;
        vector<int>lis(n,0);
        vector<int>lds(n,0);
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]<arr[i])
            {
                lis[i]=lis[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1]<arr[i])
            {
                lds[i]=lds[i+1]+1;
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(lis[i]!=0&&lds[i]!=0)
            ans=max(ans,lis[i]+lds[i]+1);
        }
        return ans>=3?ans:0;
        
    }
};