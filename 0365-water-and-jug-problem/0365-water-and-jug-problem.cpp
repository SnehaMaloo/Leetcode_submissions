class Solution {
public:
    int solve(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return solve(b,a%b);
    }
    bool canMeasureWater(int jug1, int jug2, int t) {
        if(jug1+jug2<t)
        {
            return false;
        }
        int gcd=solve(jug1,jug2);
        if(t%gcd==0)
        {
            return true;
        }
        return false;
    }
};