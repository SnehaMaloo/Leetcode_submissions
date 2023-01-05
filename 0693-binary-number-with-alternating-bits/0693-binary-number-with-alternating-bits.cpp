class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastbit=(n&1);
        n=n>>1;
        while(n!=0)
        {
            if(!((n&1)^lastbit))
            {
                return false;
            }
            lastbit=(n&1);
            n=n>>1;
        }
        return true;
    }
};