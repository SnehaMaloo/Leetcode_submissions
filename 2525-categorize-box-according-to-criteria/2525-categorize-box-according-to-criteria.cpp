class Solution {
public:
    string categorizeBox(long long l, long long b, long long h, int m) {
        long long volume=l*b*h;
        bool ok1=(l>=1e4||b>=1e4||h>=1e4||(volume>=1e9));
        bool ok2=(m>=100);
        if(ok1&&ok2)
        {
            return "Both";
        }
        if((!ok1)&&(!ok2))
        {
            return "Neither";
        }
        if(ok1)
        {
            return "Bulky";
        }
        return "Heavy";
    }
};