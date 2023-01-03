//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        n++;
        int cnt=0;
        int x=n,i=1;
        while(n!=0)
        {
            cnt+=((x)/(1<<i))*(1<<(i-1));
            if((x%(1<<i))>(1<<(i-1)))
            {cnt+=(x%(1<<i))-(1<<(i-1));}
            i++;
            n=n>>1;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends