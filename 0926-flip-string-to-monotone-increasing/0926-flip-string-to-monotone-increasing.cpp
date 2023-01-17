class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int i,cnt1=0,res=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt1++;
            }
            else
            {
                res=min(cnt1,res+1);
            }
        }
        return res;
        
    }
};