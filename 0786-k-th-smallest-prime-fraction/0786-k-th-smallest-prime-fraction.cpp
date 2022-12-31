class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        vector<int>res;
        int n=A.size();
        double low=0,high=1;
        int p=0,q=1;
        while(low<high)
        {
            p=0;
            double mid=(low+high)/2;
            int cnt=0;
            for(int i=0,j=0;i<n;i++)
            {
                while((j<n)&&(A[i]>mid*A[j]))
                {
                    j++;
                }
                cnt+=n-j;
                if(j<n&&p*A[j]<q*A[i])
                {
                    p=A[i];
                    q=A[j];
                }
            }
            if(cnt<k)
            {
                low=mid;
            }
            else if(cnt>k)
            {
                high=mid;
            }
            else
            {
                res.push_back(p);
                res.push_back(q);
                return res;
            }
        }
        return res;
    }
};