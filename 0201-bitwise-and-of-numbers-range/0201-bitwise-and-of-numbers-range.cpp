class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=1;
        while(left!=right)
        {
            left>>=1;
            right>>=1;
            i<<=1;
        }
        return i*left;
    }
};