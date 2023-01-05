class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int m=words.size();
        int n=s.length(),cnt=0;
        unordered_map<string,bool>st;
        for(int i=0;i<m;i++)
        {
            string curr=words[i];
            int k=0;
            if(st.find(curr)!=st.end())
            {
                cnt+=st[curr];
                continue;
            }
            for(int j=0;j<n;j++)
            {
                if(s[j]==curr[k])
                {
                    k++;
                    if(k>=curr.length())
                    {
                        break;
                    }
                }
            }
            if(k>=curr.length())
            {
                st[curr]=true;
                cnt++;
            }
            else
            {
                st[curr]=false;
            }
        }
        return cnt;
    }
};