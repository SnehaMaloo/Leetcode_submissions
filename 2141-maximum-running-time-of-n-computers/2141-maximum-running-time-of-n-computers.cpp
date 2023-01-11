class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        int m=b.size();
        sort(b.begin(),b.end());
        long long int sum=accumulate(b.begin(),b.end(),0LL);
        int k=0;
        while(b[m-1-k]>(sum/(n-k)))
        {
            sum-=b[m-1-k];
            k++;
        }
        return (sum/(n-k));
    }
};