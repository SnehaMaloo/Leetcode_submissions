class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int len=strs[0].length();
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};