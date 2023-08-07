//{ Driver Code Starts



#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

int solve(int a,int b,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int val=solve(b%a,a,&x1,&y1);
    (*x)=y1-(b/a)*x1;
    (*y)=x1;
    return val;
}
class Solution{
public:
    vector<int> gcd(int a, int b){
        int x,y;
        if(a>b)
        {
            vector<int>res= gcd(b,a);
            swap(res[1],res[2]);
            return res;
        }
        int ans=solve(a,b,&x,&y);
        return {ans,x,y};
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        vector<int> v = ob.gcd(a,b);
        if(v.size()!=3)
            return 0;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    return 0; 
}
// } Driver Code Ends