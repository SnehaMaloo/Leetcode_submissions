class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x=a|b;
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            if((x&(1<<i))!=(c&(1<<i)))
            {
                if(x&(1<<i))
                {
                    cnt+=((a&(1<<i))!=0)+((b&(1<<i))!=0);
                    
                }
                else
                {
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};