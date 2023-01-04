class Solution {
public:
    int minFlips(int a, int b, int c) {
        int z=a|b;
        z=z^c;
        int i=0,cnt=0;
        while(z!=0)
        {
            if(z&1==1)
            {
                cnt++;
                if((c&1)==0)
                {
                    cnt+=((a&(1<<i))&&(b&(1<<i)));
                }
            }
            z=z>>1;
            c=c>>1;
            i++;
        }
        return cnt;
    }
};