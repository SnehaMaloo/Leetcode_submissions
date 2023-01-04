class Solution {
public:
    int xorOperation(int n, int start) {
        int xor_0=0;
        int i;
        for(i=0;i<n;i++)
        {
            xor_0^=(start+2*i);
        }
        return xor_0;
    }
};