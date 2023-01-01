class Solution {
public:
    bool wordPattern(string pat, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,bool>mp2;
        int n=pat.size(),i,j=0;
        for(i=0;i<n;i++)
        {
            string res="";
            while(j<s.length()&&s[j]!=32)
            {
                res+=s[j];
                j++;
            }
            if(res=="")
            {
                return false;
            }
            else if(mp1.find(pat[i])==mp1.end()&&mp2.find(res)==mp2.end())
            {
                mp1[pat[i]]=res;
                mp2[res]=true;
            }
            else if(mp1[pat[i]]!=res||mp2[res]==false)
            {
                return false;
            }
            j++;
        }
        if(j>=s.length())
        {
            return true;
        }
        return false;
    }
};