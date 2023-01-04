class Solution {
public:
    int getSum(int a, int b) {
      int c=0;
        while(b!=0)
        {
            int temp=(a^b);
            c=(a&b);
            b=(unsigned int)(c)<<1;
            a=temp;
        }
        return a;
    }
};