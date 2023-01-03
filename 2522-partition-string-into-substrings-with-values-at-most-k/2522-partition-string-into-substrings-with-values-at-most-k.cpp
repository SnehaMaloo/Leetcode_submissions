class Solution {
public:
    int minimumPartition(string s, int k) {
        long long int n=s.length(),num=0,cnt=1;
        for(int i=0;i<n;i++)
        {
            if(num*10+s[i]-48>k)
            {
                cnt++;
                num=0;
            }
            num=num*10+s[i]-48;
            if(num>k)
            {
                return -1;
            }
        }
        return cnt;
    }
};