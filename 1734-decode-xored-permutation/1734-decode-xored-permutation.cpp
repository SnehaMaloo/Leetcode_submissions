class Solution {
public:
    vector<int> decode(vector<int>& en) {
        int n=en.size();
        n++;
        int xor_0=0;
        vector<int>arr(n,0);
        if(n%4==0)
        {
            xor_0=n;
        }
        else if(n%4==1)
        {
            xor_0=1;
        }
        else if(n%4==2)
        {
            xor_0=n+1;
        }
        int i=1;
        for(i=1;i<(n-1);i=i+2)
        {
            xor_0^=en[i];
        }
        arr[0]=xor_0;
        for(int i=1;i<n;i++)
        {
            arr[i]=en[i-1]^arr[i-1];
        }
        return arr;
    }
};