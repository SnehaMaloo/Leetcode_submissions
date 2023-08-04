//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
bool compare(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
}
class Solution{
    public:
    int overlap(vector<pair<int,int>>intervals, int n){
        vector<pair<int,int>>vc;
        for(int i=0;i<n;i++)
        {
            int x=intervals[i].first;
            int y=intervals[i].second;
            vc.push_back({x,1});
            vc.push_back({y,-1});
        }
        sort(vc.begin(),vc.end(),compare);
        int ans=0;
        int cnt=0;
        for(int i=0;i<2*n;i++)
        {
            cnt+=vc[i].second;
            ans=max(ans,cnt);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends