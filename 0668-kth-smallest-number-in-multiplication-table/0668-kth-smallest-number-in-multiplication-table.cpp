class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n;
        while(low<high)
        {
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=1,j=n;i<=m;i++)
            {
                while((j>0)&&(i*j)>mid)
                {
                    j--;
                }
                cnt+=j;
            }
            if(cnt<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};