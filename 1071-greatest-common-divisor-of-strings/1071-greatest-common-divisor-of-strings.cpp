class Solution {
public:
    int gcd(int n1,int n2)
    {
        if(n2==0)
        {
            return n1;
        }
        return gcd(n2,n1%n2);
    }
    string getit(string&s1)
    {
        int m=s1.length();
        string temp="";
        for(int i=0;i<m;i++)
        {
            temp+=s1[i];
            int curr=temp.length();
            if(m%curr!=0)
            {
                continue;
            }
            else
            {
                string tempcurr="";
                int len=m/curr;
                while(len!=0)
                {
                    tempcurr+=temp;
                    len--;
                }
                if(tempcurr==s1)
                {
                    return temp;
                }
            }
        }
        return temp;
    }
    string gcdOfStrings(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();
        if(n1<n2)
        {
            return gcdOfStrings(str2,str1);
        }
        string s1=getit(str1);
        string s2=getit(str2);
        n1=n1/(s1.length());
        n2=n2/(s2.length());
        string ans="";
        if(s1==s2)
        {
            n2=gcd(n1,n2);
            while(n2!=0)
            {
                ans=ans+s2;
                n2--;
            }
        }
        return ans;
    }
};