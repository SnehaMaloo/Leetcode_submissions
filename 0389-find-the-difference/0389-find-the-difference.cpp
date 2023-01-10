class Solution {
public:
    char findTheDifference(string s, string t) {
        int num=0;
        int n1=s.length(),n2=t.length(),i;
        for(i=0;i<n1;i++)
        {
            num^=(1<<(s[i]-'a'));
        }
        for(i=0;i<n2;i++)
        {
            num^=(1<<(t[i]-'a'));
        }
        i=0;
        while(num!=0)
        {
            num=num>>1;
            i++;
        }
        return char('a'+i-1);
    }
};