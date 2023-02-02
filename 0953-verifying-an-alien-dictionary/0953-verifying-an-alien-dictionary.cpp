class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        int n=words.size();
        for(int i=0;i<26;i++)
        {
            mp[order[i]]=i;
        }
        for(int i=0;i<(n-1);i++)
        {
            int x=0;
            int m=min(words[i].length(),words[i+1].length());
            while(x<m&&words[i][x]==words[i+1][x])
            {
                x++;
            }
            if(x==m)
            {
                if(words[i].length()>words[i+1].length())
                {
                    return false;
                }
                continue;
            }
            else if(mp[words[i][x]]>mp[words[i+1][x]])
            {
                return false;
            }
        }
        return true;
    }
};