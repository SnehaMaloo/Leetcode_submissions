class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x=0;
        for(int i=31;i>=0;i--)
        {
            if(n&(1<<i))
            {
                x+=(1<<(31-i));
            }
        }
        return x;
    }
};