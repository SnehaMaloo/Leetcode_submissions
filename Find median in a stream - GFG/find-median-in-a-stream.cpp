//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if((maxh.size()==0)||(maxh.size()!=0&&x<=maxh.top()))
        {
            maxh.push(x);
        }
        else
        {
            minh.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if((maxh.size()-minh.size())==2)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(minh.size()>maxh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double median;
        if((maxh.size()+minh.size())%2==0)
        {
            median=double((maxh.top()+minh.top())/2);
        }
        else
        {
            median=double(maxh.top());
        }
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends