class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        unordered_map<int,int>mp1,mp2;
        int n=s.length();
        int i;
        for(int i=0;i<n;i++)
        {
            mp1[s[i]]++;
            mp2[target[i]]++;
        }
        if((mp2['1']==0)^(mp1['1']==0))
        {
            return false;
        }
        return true;
    }
};