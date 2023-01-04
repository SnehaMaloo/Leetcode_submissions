class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        {
            return 1;
        }
        int x=n;
        int i=0;
        while(x!=0)
        {
            x=x>>1;
            i=(i<<1)+1;
        }
        i=~(i);
        n=n|i;
        return (~n);
    }
};