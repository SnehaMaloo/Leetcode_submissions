class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        unordered_map<int,int>mp1,mp2;
        mp1[0]=0;
        mp1['C'-'A']=1;
        mp1['G'-'A']=2;
        mp1['T'-'A']=3;
        vector<string>res;
        int num=0,j=0,i=0;
        while(j<n)
        {
            num<<=2;
            num|=mp1[s[j]-'A'];
            if(j-i+1<10)
            {
                j++;
            }
            else
            {
                if(mp2.find(num)!=mp2.end()&&(mp2[num]==1))
                {
                    res.push_back(s.substr(i,10));
                }
                mp2[num]++;
                num&=(~(3<<18));
                j++;
                i++;
            }
        }
        return res;
    }
};