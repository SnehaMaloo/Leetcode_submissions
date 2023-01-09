class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=0,y=0;
        int n=s.length(),m=t.length();
        for(int i=0;i<n;i++)
        {
            x^=(1<<(s[i]-'a'));
        }
        for(int i=0;i<m;i++)
        {
            y^=(1<<(t[i]-'a'));
        }
        int z=x^y;
        int cnt=0;
        while(z!=0)
        {
            z=z>>1;
            cnt++;
        }
        return (char)('a'+cnt-1);
    }
};