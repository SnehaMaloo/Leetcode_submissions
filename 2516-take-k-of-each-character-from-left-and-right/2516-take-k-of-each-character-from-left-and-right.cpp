class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        int ca=0,cb=0,cc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                ca++;
            }
            else if(s[i]=='b')
            {
                cb++;
            }
            else{
                cc++;
            }
        }
        if(ca<k||cb<k||cc<k){return -1;}
        int ans=INT_MAX;
        int j=0,i=0;
        while(j<n)
        {
            if(s[j]=='a')ca--;
            if(s[j]=='b')cb--;
            if(s[j]=='c')cc--;
            j++;
            while((i<j)&&(ca<k||cb<k||cc<k))
            {
                if(s[i]=='a')ca++;
                if(s[i]=='b')cb++;
                if(s[i]=='c')cc++;
                i++;
            }
            ans=min(ans,i+n-j);
        }
        return ans;
    }
};