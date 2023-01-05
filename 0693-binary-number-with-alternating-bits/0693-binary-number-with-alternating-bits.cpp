class Solution {
public:
    bool hasAlternatingBits(int n) {
       int x=n>>1;
        long long z=n^(x);
        return ((z&(z+1))==0);
    }
};