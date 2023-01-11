class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        int i=0,m=0;
        for(i=0;i<n;i++)
        {
            if(m==0)
            {
                for(int j=7;j>=0;j--)
                {
                    if(data[i]&(1<<j))
                    {
                        m++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(m==1||m>4)
                {
                    return false;
                }
                else if(m>=2)
                {
                    m--;
                }
            }
            else if((data[i]>>6)==(2))
            {
                m--;
            }
            else
            {
                return false;
            }
        }
        return m==0;
    }
};