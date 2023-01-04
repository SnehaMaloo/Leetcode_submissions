//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int dp[201]={0};
    cpp_int getfact(int n)
    {
        if(n<=1)
        {
            return dp[n]=1;
        }
        if(dp[n]!=0)
        {
            return dp[n];
        }
        return dp[n]=n*getfact(n-1);
    }
    cpp_int findCatalan(int n) 
    {
        int x=2*n;
        cpp_int y=getfact(x);
        return (dp[2*n]/(dp[n+1]*dp[n]));
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends