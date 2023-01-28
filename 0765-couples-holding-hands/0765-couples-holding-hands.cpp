class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int>mp;
        int n=row.size();
        for(int i=0;i<n;i++)
        {
            mp[row[i]]=i;
        }
        int pair=-1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(pair==-1)
            {
                pair=row[i];
                //cout<<pair<<" "<<i<<endl;
                continue;
            }
            else
            {
                if(pair%2==0)
                {
                    if(row[i]!=pair+1)
                    {
                        cnt++;
                        int idx=mp[pair+1];
                        mp[pair+1]=mp[row[i]];
                        mp[row[i]]=idx;
                        row[idx]=row[i];
                    }
                }
                else
                {
                    if(row[i]!=pair-1)
                    {
                        cnt++;
                        int idx=mp[pair-1];
                        mp[pair-1]=mp[row[i]];
                        mp[row[i]]=idx;
                        row[idx]=row[i];
                    }
                }
                pair=-1;
            }
            
        }
        return cnt;
    }
};